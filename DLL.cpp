#include<iostream>

using namespace std;

struct node{                           //NODE CUNSTRUCTION FOR DUBLIE LINK LIST
    int data;
    node* prev;
    node* next;
}; 

class DLL{

    private:
    node* head;
    int size=0;

    public:

          DLL(){
               head= NULL;
               size= 0;

          }

          void addFirst(int data) {
            node* n1 = new node();
            n1->data = data;
            n1->next = head;
            n1->prev = head;                               // PREV FOR DUBLIE LL
            head = n1;
        }  



 // ----------DUBLY LINK LIST PROGRAMS-----------//

       void delLDll(){
               
               node* n1=head;
               node* n2;

               while(n1->next->next!=NULL){
                         
                          n1=n1->next;
               }    
                 n2=n1->next;
                 n2->next=NULL;
                // n2->prev=NULL;
                 n1->next=NULL;
                 free(n2);

        }

        void delFDLL(){

            node* n1=head;
            node* n2;
             
             n2=n1->next;
             n1->next=NULL;
             n2->prev=NULL;
             free(n1);
             head=n2;
              
        }

        void swapL2DLL(){
                
                node* n1=head;
                node* n2;
                node* n3;

                while(n1->next->next->next!=NULL){
                    n1=n1->next;
                }
                  n2=n1->next;
                  n3=n2->next;
                  n2->next=NULL;
                  n2->prev=n3;
                  n3->next=n2;
                  n3->prev=n1;
                  n1->next=n3;
        }

        void swapF2DLL(){

            node* n1=head;
            node* n2;
            node* n3;

            n2=n1->next;
            n3=n2->next;
            n1->next=n3;
            n1->prev=n2;
            n3->prev=n1;
            n2->next=n1;
            n2->prev=NULL;
            head=n2;
        }

        void swapFLDLL(){

            node* n1= head;
            node* n2=head->next;
            node* n3;
            node* n4= head;

            while(n1->next->next!=NULL){
                n1=n1->next;
            }
                 n3=n1->next;
                 n3->next=n2;
                 n3->prev=NULL;
                 n2->prev=n3;
                 n4->next=NULL;
                 n4->prev=n1;
                 n1->next=n4;
                 head=n3;

        }

        void swapNthMthDLL(int x , int y){

            node* nX=head;
            node* n1;
            node* n2;
            node* n3;
            node* n4;
            node* nY=head;

            if(x==y){
                return;
            }

        
            while(nX->next->data!= x){
                nX=nX->next;
            }

            while(nY->next->data!= y){
                nY=nY->next;
            }
               n1=nX->next;
               n2=nY->next;
               n3=nX->prev;
               n4=nY->prev;

               nX->next=n2;
               nX->prev=n4;
               n2->prev=nX;
               n4->next=nX;
               nY->next=n1;
               nY->prev=n3;
               n1->prev=nY;
               n3->next=nY;              //NOT WORKING PROPERLY loop is infinite

        }

      
        void print(){
                node* currentnode= head;    
              
                do{
                 cout<<currentnode->data<<endl;
                 currentnode = currentnode->next;
                }while(currentnode!=NULL);
              
              return;
        }

                  
};


int main(){
    node* head=NULL;
    DLL list ;
    list.addFirst(35);
    list.addFirst(45);
    list.addFirst(55);
    list.addFirst(65);
    list.addFirst(75);
    list.addFirst(85);
    list.addFirst(95);
    cout<<"---------- LL is -----------"<<endl;
    list.print();
    cout<< "----------updated list is--------"<<endl;
    list.swapNthMthDLL(45,85);
    list.print();
    return 0;
    
}

