/*
* Program for Set Operations
* Author : Karthi Thangavel
* Revised Date : 12/12/2019
*/
#include<iostream>
#include<conio.h>
using namespace std;
class SetOperations
{
    public:
        void setUnion(int *inFirstArray,int inFirstArraySize,int *inSecondArray,int inSecondArraySize);
        void setIntersection(int *inFirstArray,int inFirstArraySize,int *inSecondArray,int inSecondArraySize);
        void setDifference(int *inFirstArray,int inFirstArraySize,int *inSecondArray,int inSecondArraySize);
        void setDisplay(int *outResultArray,int outResultArraySize);
};
int main()
{
    int inFirstArray[10];int inSecondArray[10];
    int inFirstArraySize;int inSecondArraySize;
    int i,j,flag=0;// Loop controls
    
    cout<<"Enter No Of Elements To Be In First Array:\n";
    cin>>inFirstArraySize;
    cout<<"Enter "<<inFirstArraySize<<" Elements Of First Array:\n";
    
    for(i=0;i<inFirstArraySize;i++)
    {
        cin>>inFirstArray[i];
    }
    //This part allow the user to store first array elements
    
    cout<<"Enter No Of Elements To Be In Second Array:\n";
    cin>>inSecondArraySize;
    cout<<"Enter "<<inSecondArraySize<<" Elements Of Second Array:\n";
    for(i=0;i<inSecondArraySize;i++)
    {
        cin>>inSecondArray[i];
    } //This part allow the user to store second array elements

    SetOperations s; //Object for Set Class

    //Calling the SetOperations Class member function through the object
    cout<<"Union :";
    s.setUnion(inFirstArray,inFirstArraySize,inSecondArray,inSecondArraySize);
    cout<<"Intersection :";
    s.setIntersection(inFirstArray,inFirstArraySize,inSecondArray,inSecondArraySize);
    cout<<"Difference A-B :";
    s.setDifference(inFirstArray,inFirstArraySize,inSecondArray,inSecondArraySize);
    cout<<"Difference B-A :";
    s.setDifference(inSecondArray,inSecondArraySize,inFirstArray,inFirstArraySize);
    
    return 0;
}
 
void SetOperations::setDisplay(int *outResultArray,int outResultArraySize)
{
    int i;
    for(i=0;i<outResultArraySize;i++)
    {
        cout<<outResultArray[i]<<" ";
    }
    cout<<"\n";
} //setDisplay method allows to display the final result to the output screen.
 
void SetOperations::setUnion(int *inFirstArray,int inFirstArraySize,int *inSecondArray,int inSecondArraySize)
{
    int i,j,flag=0,outResultArray[20],outResultArraySize=0;
    for(i=0;i<inFirstArraySize;i++)
    {
        outResultArray[i]=inFirstArray[i];
        outResultArraySize++;
    }// Copy the first array elements to result array.
    
    for(i=0;i<inSecondArraySize;i++)
    {
        flag=0;
        for(j=0;j<outResultArraySize;j++)
        {
            if(inSecondArray[i]==outResultArray[j])
            {
                flag=1;
                break;
            }
        } // Toggle a flag, if second array element match with result array element.
        if(flag==0)
        {
            outResultArray[outResultArraySize]=inSecondArray[i];
            outResultArraySize++;
        } //Copy the second array elements to result array, if condition is true.
    }
    setDisplay(outResultArray,outResultArraySize);
}
//setUnion allows merge two arrays without duplicate.
void SetOperations::setIntersection(int *inFirstArray,int inFirstArraySize,int *inSecondArray,int inSecondArraySize)
{
    int i,j,flag=0,outResultArray[20],outResultArraySize=0;
    
    for(i=0;i<inSecondArraySize;i++)
    {
        for(j=0;j<inFirstArraySize;j++)
        {
            if(inSecondArray[i]==inFirstArray[j])
            {
                outResultArray[outResultArraySize]=inSecondArray[i];
                outResultArraySize++;
                break;
            }
        }
    } // Compare second array elements to first array elements
    // Copy the matched elements to result Array.
    setDisplay(outResultArray,outResultArraySize);
}
//setIntersection allows identify elements which are duplicate.
void SetOperations::setDifference(int *inFirstArray,int inFirstArraySize,int *inSecondArray,int inSecondArraySize)
{
    int i,j,flag=0,outResultArray[20],outResultArraySize=0;
    for(i=0;i<inFirstArraySize;i++)
    {
        flag=0;
        for(j=0;j<inSecondArraySize;j++)
        {
            if(inFirstArray[i]==inSecondArray[j])
            {
                flag=1;
                break;
            }
        } // Toggle a flag, if second array element match with result array element.
        if(flag==0)
        {
            outResultArray[outResultArraySize]=inFirstArray[i];
            outResultArraySize++;
        }
    } //Copy the second array elements to result array, if condition is true.
    setDisplay(outResultArray,outResultArraySize);
}
//setDifference allows identify elements which are non duplicate either in firstArray or secondArray.