#include<bits/stdc++.h>
using namespace std;

int n=0,a;
deque<int>dq;

void pushleft(int x)
{
    if(n==a)
    {
        cout<<"The queue is full\n";
    }
    else
    {
        dq.push_front(x);
        cout<<"Pushed in left: "<<x<<endl;
        n++;
        return;
    }
}

void pushright(int x)
{
    if(n==a)
    {
        cout<<"The queue is full\n";
        return;
    }
    else
    {
        dq.push_back(x);
        cout<<"Pushed in right: "<<x<<endl;
        n++;
        return;
    }
}


void popleft()
{
    if(n==0)
    {
        cout<<"The queue is empty\n";
        return ;
    }
    else
    {
        cout<<"Popped from left: "<<dq.front()<<endl;
        dq.pop_front();
        n--;
        return;
    }
}

void popright()
{
    if(n==0)
    {
        cout<<"The queue is empty\n";
        return ;
    }
    else
    {
        cout<<"Popped from right: "<<dq.back()<<endl;
        dq.pop_back();
        n--;
        return;
    }
}

int main()
{
    int t,q,i,j,x,y;
    cin>>t;
    string s;

    for(i=1; i<=t; i++)
    {
        cin>>a>>q;
        cout<<"Case "<<i<<":\n";

        while(q--)
        {
            cin>>s;

            if(s=="pushLeft")
            {
                cin>>x;
                pushleft(x);
            }
            else if(s=="pushRight")
            {
                cin>>x;
                pushright(x);
            }
            else if(s=="popLeft")
            {
                popleft();
            }
            else if(s=="popRight")
            {
                popright();
            }
        }
        n=0;
        dq.clear();
    }
//

    return 0;
}
