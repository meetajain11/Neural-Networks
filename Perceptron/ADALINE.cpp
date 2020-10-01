#include<iostream>
using namespace std;
void adaline(float w_new[],float b_old,float a,float error[],float sum_of_error,float b,float y,float c_in_w[],float c_in_b,
             int x[],int t,int c,float threshold,float output)
{
    while (sum_of_error>=threshold && c<=40)
    {
        sum_of_error=0;
    //for inputs of AND GATE
       if (c%4==0)
       {
            x[0]=1;
            x[1]=1;
       }
       else if (c%4==1)
       {
            x[0]=1;
            x[1]=-1;
       }
       else if (c%4==2)
       {
            x[0]=-1;
            x[1]=1;
       }
       else
       {
            x[0]=-1;
            x[1]=-1;
       }
        if (x[0]==1 && x[1]==1)
        {
            t=1;
        }
        else
        {
            t=-1;
        }
        y=(x[0]*w_new[0]) + (x[1]*w_new[1])+ (b_old*b);
    //for delta w and delta b
        cout<<" w1 initial = "<<w_new[0]<<"    w2 initial= "<<w_new[1]<<"      b initial = "<<b <<endl;
        cout<<" x1 = "<<x[0]<<"              x2 = "<<x[1]<<"               b = "<<b<<"             yin = "<<y<<endl;
        for(int i=0;i<2;i++)
        {
            c_in_w[i]=a*(t-y)*x[i];
        }
    //for change in b
        c_in_b=a*(t-y)*b;
        cout<<" change in w1 = "<<c_in_w[0]<<" change in w2 = "<<c_in_w[1]<<" change in b = "<<c_in_b <<endl;
    //for new w and new b
        for(int i=0;i<2;i++)
        {
            w_new[i]=c_in_w[i]+w_new[i];
        }
    //for b
        b_old=b_old+c_in_b;
        cout<<" w1 = "<<w_new[0]<<"            w2 = "<<w_new[1]<<"             b = "<<b_old <<endl;

        error[c%4]=(t-y)*(t-y);

        if (c%4==3)
        {
            for (int i=0;i<4;i++)
            {
                sum_of_error=sum_of_error + error[i];
            }
            cout<<"sum error:"<<sum_of_error<<endl;
            for (int i=0;i<4;i++)
            {
                cout<<error[i]<<endl;
            }
        }
        c++;
        if ((c-1)%4==3)
        {
            adaline(w_new,b_old,a,error,sum_of_error,b,y,c_in_w,c_in_b,x,t,c,threshold,output);
        }
        else
        {
            adaline(w_new,b_old,a,error,100000,b,y,c_in_w,c_in_b,x,t,c,threshold,output);
        }
    }
    //if greater than 15 epochs it will print cannot calculate at this learning rate
    if (c>60)
    {
        cout<<"cannot train at this learning rate! :)"<<endl;
    }
        if (sum_of_error<threshold)
        {
            cout<<"ENTER VALUES FOR INPUT  :"<<endl;
            for(int i=0;i<2;i++)
            {
                cin>>x[i];
            }
            output=x[0]*w_new[0]+x[1]*w_new[1]+b_old;
            if(output>=0)
            {
                cout<<"SUCCESS!";
                return;
            }
            else
            {
                cout<<"FAILURE!";
                return;
            }

        }
        return;
}
int main()
{
    float threshold,output;
    cout<<"ENTER threshold value: "<<endl;
    cin>>threshold;
    int t,x[2];
    float b_old=0.1,w_new[2]={0.1,0.1},a;
    cout<<"ENTER LEARNING RATE:"<<endl;
    cin>>a;
    float b=1,y,c_in_w[2],c_in_b;
    float sum_of_error=100000,error[4];
    adaline(w_new,b_old,a,error,sum_of_error,b,y,c_in_w,c_in_b,x,t,0.,threshold,output);
    return 0;
}



























  /*  while (sum_of_error>=threshold)
    //while (c<2)
    {
        sum_of_error=0;
        x[0]=1;
        x[1]=1;
        if (x[0]==1 && x[1]==1)
        {
            t=1;
        }
        else
        {
            t=-1;
        }
        y=(x[0]*w_new[0]) + (x[1]*w_new[1])+ (b_old*b);
    //for delta w and delta b
        cout<<" w1 initial = "<<w_new[0]<<"    w2 initial= "<<w_new[1]<<"      b initial = "<<b <<endl;
        cout<<" x1 = "<<x[0]<<"              x2 = "<<x[1]<<"               b = "<<b<<"             yin = "<<y<<endl;
        for(int i=0;i<2;i++)
        {
            c_in_w[i]=a*(t-y)*x[i];
        }
    //for change in b
        c_in_b=a*(t-y)*b;
        cout<<" change in w1 = "<<c_in_w[0]<<" change in w2 = "<<c_in_w[1]<<" change in b = "<<c_in_b <<endl;
    //for new w and new b
        for(int i=0;i<2;i++)
        {
            w_new[i]=c_in_w[i]+w_new[i];
        }
    //for b
        b_old=b_old+c_in_b;
        cout<<" w1 = "<<w_new[0]<<"            w2 = "<<w_new[1]<<"             b = "<<b_old <<endl;

        error[0]=(t-y)*(t-y);
        x[0]=1;
        x[1]=-1;
        if (x[0]==1 && x[1]==1)
        {
            t=1;
        }
        else
        {
        t=-1;
        }
        y=(x[0]*w_new[0]) + (x[1]*w_new[1])+ (b_old*b);
    //for delta w and delta b
        cout<<" w1 initial = "<<w_new[0]<<"    w2 initial= "<<w_new[1]<<"      b initial = "<<b <<endl;
        cout<<" x1 = "<<x[0]<<"              x2 = "<<x[1]<<"               b = "<<b<<"             yin = "<<y<<endl;
        for(int i=0;i<2;i++)
        {
            c_in_w[i]=a*(t-y)*x[i];
        }
    //for change in b
        c_in_b=a*(t-y)*b;
        cout<<" change in w1 = "<<c_in_w[0]<<" change in w2 = "<<c_in_w[1]<<" change in b = "<<c_in_b <<endl;
    //for new w and new b
        for(int i=0;i<2;i++)
        {
            w_new[i]=c_in_w[i]+w_new[i];
        }
    //for b
        b_old=b_old+c_in_b;
        cout<<" w1 = "<<w_new[0]<<"            w2 = "<<w_new[1]<<"             b = "<<b_old <<endl;

        error[1]=(t-y)*(t-y);
        x[1]=1;
        x[0]=-1;
   // x[2]={-1,1};
        if (x[0]==1 && x[1]==1)
        {
            t=1;
        }
        else
        {
            t=-1;
        }
        y=(x[0]*w_new[0]) + (x[1]*w_new[1])+ (b_old*b);
    //for delta w and delta b
        cout<<" w1 initial = "<<w_new[0]<<"    w2 initial= "<<w_new[1]<<"      b initial = "<<b <<endl;
        cout<<" x1 = "<<x[0]<<"              x2 = "<<x[1]<<"               b = "<<b<<"             yin = "<<y<<endl;
        for(int i=0;i<2;i++)
        {
            c_in_w[i]=a*(t-y)*x[i];
        }
    //for change in b
        c_in_b=a*(t-y)*b;
        cout<<" change in w1 = "<<c_in_w[0]<<" change in w2 = "<<c_in_w[1]<<" change in b = "<<c_in_b <<endl;
    //for new w and new b
        for(int i=0;i<2;i++)
        {
            w_new[i]=c_in_w[i]+w_new[i];
        }
    //for b
        b_old=b_old+c_in_b;
        cout<<" w1 = "<<w_new[0]<<"            w2 = "<<w_new[1]<<"             b = "<<b_old <<endl;

        error[2]=(t-y)*(t-y);
    //x[2]={-1,-1};
        x[1]=-1;
        x[0]=-1;
        if (x[0]==1 && x[1]==1)
        {
            t=1;
        }
        else
        {
            t=-1;
        }
        y=(x[0]*w_new[0]) + (x[1]*w_new[1])+ (b_old*b);
    //for delta w and delta b
        cout<<" w1 initial = "<<w_new[0]<<"    w2 initial= "<<w_new[1]<<"      b initial = "<<b <<endl;
        cout<<" x1 = "<<x[0]<<"              x2 = "<<x[1]<<"               b = "<<b<<"             yin = "<<y<<endl;
        for(int i=0;i<2;i++)
        {
            c_in_w[i]=a*(t-y)*x[i];
        }
    //for change in b
        c_in_b=a*(t-y)*b;
        cout<<" change in w1 = "<<c_in_w[0]<<" change in w2 = "<<c_in_w[1]<<" change in b = "<<c_in_b <<endl;
    //for new w and new b
        for(int i=0;i<2;i++)
        {
            w_new[i]=c_in_w[i]+w_new[i];
        }
    //for b
        b_old=b_old+c_in_b;
        cout<<" w1 = "<<w_new[0]<<"            w2 = "<<w_new[1]<<"             b = "<<b_old <<endl;

        error[3]=(t-y)*(t-y);
        for (int i=0;i<4;i++)
        {
            sum_of_error=sum_of_error + error[i];
        }
    cout<<"sum error:"<<sum_of_error<<endl;
        for (int i=0;i<4;i++)
        {
            cout<<error[i]<<endl;
        }
      //  c++;
    }

    cout<<"ENTER VALUES FOR INPUT  :"<<endl;
    for(int i=0;i<2;i++)
    {
        cin>>x[i];
    }
    output=x[0]*w_new[0]+x[1]*w_new[1]+b_old;
    if(output>=0)
    {
        cout<<"SUCCESS!";
    }
    else
    {
        cout<<"FAILURE!";
    }
    return 0;
}
*/
