C/C++关于64位整数输入输出

 

类型 long long       __int64    intmax_t

 

格式   %lld              %I64d      %I64d

 

在Dev C++中，三种类型均需用%I64d格式输出 ，c语言中intmax_t需要用到头文件stdint.h

 

C++采用cin输入时，两种类型均可。

 

 C语言范例：

 

 eg1:

 

    #include<stdio.h>

    int main()

    {

        long long a;

        scanf("I64d",&a);

        print("I64d\n",a);

        system("pause");

        return 0;

    }

 

 eg2:

 

   #include<stdio.h>

    int main()

    {

        __int64 a;

        scanf("%I64d",&a);

        printf("%I64d\n",a);

        system("pause");

        return 0;

    }

  

  eg3:

    #include<stdio.h>

    #include<stdint.h>

    int main()

    {

        intmax_t a;

        scanf("I64d",&a);

        printf("I64d\n",a);

        system("pause");

        return 0;

    }

 

 

 

 

 C++范例： 

 

 

  eg4:

    #include<iostream>

    using namespacestd;

    int main()

    {

        intmax_t a,b;

        cin>>a>>b;

       cout<<a+b<<endl;

        system("pause");

        return 0;

    }

 

eg5:

 

     #include<iostream>

    using namespace std;

    int main()

    {

        long long a,b;

        cin>>a>>b;

        cout<<a+b<<endl;

        system("pause");

        return 0;

    }

 

 eg6:

 

    #include<iostream>

    using namespace std;

    int main()

    {

        intmax_t a,b;

        cin>>a>>b;

        cout<<a+b<<endl;

        system("pause");

        return 0;

    }

 

 

 

 

 