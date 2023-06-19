#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    int a, i=0;
    string text, old, password1,password2,pass, password0, name, age, user, word, word1;
    string creds[2] , cp[2];
    cout<<"      Security System"<<endl;
    cout<<"_____________________________________"<<endl<<endl;
    cout<<"                1.Register           "<<endl;
    cout<<"                2.Login              "<<endl;
    cout<<"                3.Change Password    "<<endl;
    cout<<"________________4.End Program________"<<endl;
    do{
        cout<<endl<<endl;
        cout<<"Enter your choice";
        cin>>a;-
        switch(a)
        {
            case 1:{
                	cout<<"__________________________________"<<endl<<endl;
                	cout<<"|------------Register------------|"<<endl;
                	cout<<"|________________________________|"<<endl;
                	cout<<"Please enter Username:-";
                	cin>>name;
                	cout<<"Please enter password:-";
                	cin>>password0;
                	cout<<"Please enter your age";
                	cin>>age;

                	ofstream of1;
                	of1.open("file.txt");
                	if(of1.is_open()){
                    	of1<<name<<"\n";
                    	of1<<password0;
                    	cout<<"Registration Successfull"<<endl;
                	}
            	break;
        	}
            case 2:{
            		i=0;
                	cout<<"__________________________________"<<endl<<endl;
                	cout<<"|--------------Login-------------|"<<endl;
                	cout<<"|________________________________|"<<endl;
                
                	ifstream of2;
                	of2.open("file.txt");
                	cout<<"Please enter Username:-";
                	cin>>name;
                	cout<<"Please enter password:-";
                	cin>>pass;
                	
                	if(of2.is_open())
					{
                    	while(!of2.eof())
						{
                        	while(getline(of2, text)){
                            istringstream iss(text);
                            	iss>>word;
                            	creds[i]=word;
                            	i++;
                        	}
                			if(user==creds[0] && pass==creds[1]){
                    			cout<<"---Login in successfull---";
                    			cout<<endl<<endl;

			                    cout<<"Details: "<<endl;

            			        cout<<"Username: "+ name<<endl;
                  			  cout<<"Password: "+ pass<<endl;
                    		cout<<"Age: "+ age<<endl;
                			}
                			else{
                 				cout<<endl<<endl;
                   				cout<<"Incorrect Credentials"<<endl;
                			    cout<<"|       1. press 3 to login             |"<<endl;
                			    cout<<"|       2. press 3 to change password   |"<<endl;
                			    break;
                			}
                			
            			}
            		}
        		break;
        	}
    
        	   case 3:{
          		i=0;
            	cout<<"-------------------Change Password--------------------"<<endl;

                	ifstream of0;
                	of0.open("file.txt");
                	cout<<"Enter old password:-";
                	cin>>old;
                	if(of0.is_open())
					{
                     while(of0.eof())
					{
                        while(getline(of0, text)){
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }
                        if(old==cp[1])
						{
                          of0.close();
                          ofstream of1;
                          if(of1.is_open()){
                            	cout<<"Enter your new password:- ";
                                cin>>password1;
                                cout<<"Enter your password again:- ";
                                cin>>password2;
                                if(password1==password2){
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Password changed successfully"<<endl;
                                }
                                else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password do not match"<<endl;
                                }
                          }
                      }
                      else{
                         cout<<"Please enter a valid password"<<endl;
                         break;
                      }
                  }
              }
            break;
           }
           case 4:
		    {
            	cout<<"____________ThankYou!________________";
            	break;
               }
            	
          	   default:
                cout<<"Enter a valid choice";
                
    	}
	}
    while (a!=4);
    return 0;
    
}
