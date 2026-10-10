#include <iostream>
using namespace std;

    class A{
            protected:
        string faculty ="Rahul sharma";
        int salary = 89000;
        
        string student = "shnay Yadav";
        int marks = 98;
        
        public:
        void access_faculty()
            {
                cout<<"facultu info: " <<faculty<< endl<< salary<<endl;
                cout<<"student info: " << student<<endl<< marks<< endl; 
            }
        void access_student()
            {
                cout<<"student info" << student<<endl<< marks<< endl; 
            }
    };

    class B : public A{
        public:
            void x()
                {
                        string pass;
                cout<<"Enter passward (case sensitive)"<< endl;
                cin>>pass;
                
                if(pass == "faculty")   // faculty
                    {
                        access_faculty();
                    }
                else if(pass == "student") // student
                    {
                        access_student();
                    }
                    else cout<<"incorrect pass";
                }
    };

int main()
{
    B *obj1= new B;
   // B obj1;
   obj1->x();

    return 0;
}
