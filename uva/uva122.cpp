#include <iostream>
#include <list>
#include <string>
#include <sstream>
using namespace std;
//节点结构体，存储节点的值及左右子节点
struct NODE {int nVal; NODE *pL; NODE *pR;}
//NullNode为空节点标本
const NullNode = {0, 0, 0};
//删除树
void DeleteTree(NODE *pPar) {
    if (pPar != NULL) {
        //深度遍例删除左右子节点
        DeleteTree(pPar->pL), DeleteTree(pPar->pR);
    }
    delete pPar;
}
//为树增加节点
NODE* AddChild(NODE *pPar, int nVal, const char *pPath) {
    //如果父为空，则建立父节点
    if (pPar == 0) {
        pPar = new NODE(NullNode);
    }
    //根据当前路径字符串做不同操作
    switch (*pPath) {
    //遇到右括号，说明路径结束，为当前父节点赋值
    case ')': pPar->nVal = (pPar->nVal == 0 && nVal != 0) ? nVal : -1; break;
    //继续建立左/右子节点
    case 'L': pPar->pL = AddChild(pPar->pL, nVal, pPath + 1); break;
    case 'R': pPar->pR = AddChild(pPar->pR, nVal, pPath + 1); break;
    }
    return pPar;
}
//主函数
int main(void) {
    //树的根结点
    NODE *pRoot = 0;
    //循环处理输入的每一个节点数据
    for (string strToken; cin >> strToken;) {
        //获得节点数据字符串指针
        const char *pStr = strToken.c_str();
        int nLen = strToken.length(), nVal = 0;
        //如果第二个字符不是右括号，则添加节点后继续输入
        if (pStr[1] != ')') {
            //将字符串转为数字
            for (; isdigit(*++pStr); nVal = nVal * 10 + *pStr - '0');
            if (*pStr != ',') while(true);
            //在树中添加该节点
            pRoot = AddChild(pRoot, nVal, ++pStr);
            continue;
        } //如果第二字符是右括号，说明一棵树输入结束，进行遍例
        list<NODE*> Level(1, pRoot);
        stringstream ssResult;
        //依次遍例每一层。用Level存储一层的节点，Level非空则继续遍例
        for (list<NODE*>::iterator i = Level.begin(); !Level.empty();
            //如果一层遍例结束，则回到起点
            i = (i == Level.end() ? Level.begin() : i)) {
            //移除当前节点
            NODE *pTemp = *i;
            i = Level.erase(i);
            //如果该节点为空，则直接继续进行下一个节点
            if (pTemp == 0) {
                continue;
            }//否则在原位置上增加子节点
            //如果该节点的值小于或等于0，说明其重复定义或未定义
            if (pTemp->nVal <= 0) {
                //清空数据，返回错误。
                Level.clear();
                ssResult.str("");
                break;
            }//正确的结点
            //输入其值，并在原位置上插入其子节点
            ssResult << pTemp->nVal << ' ';
            i = Level.insert(i, pTemp->pL), ++i;
            i = Level.insert(i, pTemp->pR), ++i;
        }
        //删除原树，避免内存泄露。
        DeleteTree(pRoot);
        pRoot = 0;
        strToken = ssResult.str();
        //如果结果为空，说明所给数据有错
        if (strToken.empty()) {
            strToken = "not complete";
        } //对于正确结果要去掉最后的一个空格
        else {
            strToken.erase(strToken.end() - 1);
        }
        //输出结果
        cout << strToken << endl;
    }
    return 0;
}