#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int f[0];int a[0];int r[0];
    cout<<"\t!!WELCOME!!"<<endl;
    string arr1[10]={"Glowy LED Flashlight","Sunscreen Lotion","Crunchy Cashew Nuts","Sparky Electric Toothbrush","Fluffy Pillow","Breezy Air Cooler","Fruity Lip Balm","Smarty Smart Watch","Cozy Blanket","Tasty Tea"};
    string arr2[10]={"A multi-color LED flashlight that can cast different hues of light for various purposes.","A sunscreen lotion that protects your skin from harmful UV rays and nourishes it with natural ingredients.","A pack of roasted and salted cashew nuts that are perfect for snacking and sharing.","An electric toothbrush that cleans your teeth more effectively than a manual one.","A soft and comfortable pillow that will give you a good night's sleep.","An air cooler that cools your room without consuming too much electricity.","A lip balm that moisturizes your lips and gives them a hint of color.","A smart watch that tracks your fitness and health activities and connects with your smartphone.","A warm and cozy blanket that will keep you snug and cozy on cold nights.","A pack of tea bags that offer a refreshing and soothing drink."};
    float arr3[10]={999,349,299,1499,599,4999,149,9999,1199,199};
    int n;
    cout<<"1.Product's\n2.Your Cart\n3.exit\n";
    cin>>n;
    if(n==1)
    {
        int s;
        for(int i=0;i<10;i++)
        {
            cout<<endl;
            cout<<i+1<<"."<<arr1[i]<<endl;
            cout<<"Price :"<<arr3[i]<<"₹"<<endl;
            cout<<"Description :"<<arr2[i]<<endl<<endl;
        }
        cout<<"1.Choose a Product to Buy: \n2.Modified the Prodcut\n";
        cin>>s;
        if(s==1)
        {
            cout<<"Enter the Product No :";
            cin>>f[1];
            cout<<"\nEnter the quantity :";
            cin>>a[1];
            // add the product and the quantity to the cart
            r[0]++; // increment the number of items in the cart
            r[r[0]] = f[1]; // store the product number in the cart
            r[r[0]+10] = a[1]; // store the quantity in the cart
            cout<<"\nProduct added to the cart successfully.\n";
        }
        else if(s==2)
        {
            // modify the product details
            cout<<"Enter the Product No to modify :";
            cin>>f[1];
            cout<<"\nEnter the new name :";
            cin>>arr1[f[1]-1];
            cout<<"\nEnter the new price :";
            cin>>arr3[f[1]-1];
            cout<<"\nEnter the new description :";
            cin.ignore(); // ignore the newline character
            getline(cin,arr2[f[1]-1]); // read the whole line
            cout<<"\nProduct modified successfully.\n";
        }
        else
        {
            cout<<"\nInvalid choice.\n";
        }
    }
    else if(n==2)
    {
        // display the cart details
        cout<<"\nYour Cart:\n";
        float total = 0; // initialize the total amount
        for(int i=1;i<=r[0];i++)
        {
            // print the product name, quantity and price
            cout<<i<<". "<<arr1[r[i]-1]<<" x "<<r[i+10]<<" = "<<arr3[r[i]-1]*r[i+10]<<"₹\n";
            // add the product price to the total amount
            total += arr3[r[i]-1]*r[i+10];
        }
        cout<<"\nTotal Amount = "<<total<<"₹\n";
        cout<<"\nDo you want to checkout? (Y/N)\n";
        char c;
        cin>>c;
        if(c=='Y' || c=='y')
        {
            // process the payment and confirm the order
            cout<<"\nPlease enter your payment method (1.Credit Card, 2.Debit Card, 3.Net Banking, 4.Cash on Delivery)\n";
            int p;
            cin>>p;
            switch(p)
            {
                case 1:
                    cout<<"\nPlease enter your credit card number, expiry date and CVV\n";
                    // validate the credit card details and deduct the amount
                    cout<<"\nPayment successful.\n";
                    break;
                case 2:
                    cout<<"\nPlease enter your debit card number, expiry date and CVV\n";
                    // validate the debit card details and deduct the amount
                    cout<<"\nPayment successful.\n";
                    break;
                case 3:
                    cout<<"\nPlease enter your bank name, account number and IFSC code\n";
                    // validate the bank details and transfer the amount
                    cout<<"\nPayment successful.\n";
                    break;
                case 4:
                    cout<<"\nYou have chosen cash on delivery option. You will pay the amount when the product is delivered to you.\n";
                    break;
                default:
                    cout<<"\nInvalid payment method.\n";
                    break;
            }
            cout<<"\nYour order has been confirmed. Thank you for shopping with us.\n";
        }
        else
        {
            // cancel the order and clear the cart
            cout<<"\nYou have cancelled your order. Your cart is now empty.\n";
            r[0] = 0; // reset the number of items in the cart
        }
    }
    else if(n==3)
    {
        // exit the program
        cout<<"\nThank you for visiting us. Have a nice day.\n";
        return 0;
    }
    else
    {
        // handle invalid input
        cout<<"\nInvalid option. Please try again.\n";
    }
}
