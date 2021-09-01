#include <iostream>
using namespace std;

class node
{
public:
 int data;
 node *next;
};
void push(node** headref,int newdata)
{
    node* newnode= new node();
    newnode->data = newdata;
    newnode->next = *(headref);
    *(headref) = newnode;
}

void insertmid(node* prevnode,int newdata)
{
node* newnode = new node();
newnode->data = newdata;
newnode->next = prevnode->next;
prevnode->next = newnode;
}

void append(node** headref,int newdata)
{
    node* temp = *headref;
    node* newnode = new node();
    newnode->data = newdata;
    newnode->next = NULL;
    if(*headref== NULL)
    {*headref = newnode;
    return;}
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    
}
    void kpos(node*headref,int newdata,int pos)
    {
       int i=1;
        node* temp;
        temp=headref;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
       node* newnode = new node();
        newnode->data = newdata;
        newnode->next=temp->next;
        temp->next=newnode;
        
        
    }
    void printlist(node* node)
    {
        while(node!=NULL)
        {
            cout<<" "<<node->data<<"->";
            node= node->next;
        }
    }
    void count(node* head)
    {
        int coun =0;
        node* temp=head;
        while(temp!=NULL)
        {
            temp = temp->next;
            coun++;
            
        }
        cout<<"the linked list contains "<<coun;
    }
/* Driver code*/
int main() 
{ 
    /* Start with the empty list */
    node* head = NULL; 
      
    // Insert 6. So linked list becomes 6->NULL 
    append(&head, 6); 
      
    // Insert 7 at the beginning. 
    // So linked list becomes 7->6->NULL 
    push(&head, 7); 
    
      
    // Insert 1 at the beginning. 
    // So linked list becomes 1->7->6->NULL 
      
    // Insert 4 at the end. So 
    // linked list becomes 1->7->6->4->NULL 
    append(&head, 4); 
      
    // Insert 8, after 7. So linked 
    // list becomes 1->7->8->6->4->NULL 
    insertmid(head->next, 8); 
    kpos(head,84,4);
    
      
    cout<<"Created Linked list is: "; 
    printlist(head); 
    count(head);
    
      
    return 0; 
}