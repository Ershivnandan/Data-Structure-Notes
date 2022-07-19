#include<iostream>

using namespace std;

 struct  node {                            //NODE CUNSTRUCTION FOR SINGLY LINK LIST
    int data;
    node* next;
}; 


class LL {

    private :
        node* head;
        int size;

    public:
        LL() {                                              //constructor to asign the initial values of node
            head = NULL;
            size = 0;
        }  

        void addFirst(int data) {
            node* n1 = new node();
            n1->data = data;
            n1->next = head;
           // n1->prev = head;                               // PREV FOR DUBLIE LL
            head = n1;
        }  

        // ----------SINGLY LINK LIST PROGRAMMS----------//
        
         void dellast(){
          node* n1=head;
         
             while(n1->next->next!=NULL){
 
                 n1=n1->next;        
            }
             n1->next=NULL;
             node* last=n1->next;
             free(last);  
             
         }

        void delfirst(){
            node* n1=head;
            node* n2=n1->next;

            n1->next=NULL;
            free(n1);
            head=n2;
        }

        void swapL2(){
              node* n1= head;
              node* n2;
              node* n3;


              while(n1->next->next->next!=NULL){
                    n1=n1->next;
              }
                 
                  n2=n1->next;
                  n3=n2->next;
                  n1->next=n3;
                  n3->next=n2;
                  n2->next=NULL;
        }
        
        void swapFL(){

           node* n1=head;
           node* n2;
           node* n3=head;
           node* n4=head->next;

           while(n1->next->next!=NULL){
              
                 n1=n1->next;
           }
               n2=n1->next;
               n2->next=n4;
               n1->next=n3;
               n3->next=NULL;
               head=n2;

        }

        void swapF2(){

            node* n1=head;
            node* n2;
            node* n3;

              n2=n1->next;
              n3=n2->next;
              n2->next=n1;
              n1->next=n3;
              head=n2;
        }

        void swapNthMth( int x , int y){
                       
              node* n1;
              node* cx=head;
              node* n2;
              node* cy=head;
          

              while(cx->next->data !=x){
                cx=cx->next;
              }
              
               while(cy->next->data !=y){
                cy=cy->next;
              }   
                  n1=cx->next;
                  n2=cy->next;
                  n2->next=n1->next; 
                  cx->next=n2;
                  n1->next=n2->next;
                  cy->next=n1;              

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
    LL list ;
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
    list.swapL2();
    list.print();
    return 0;
    
}
