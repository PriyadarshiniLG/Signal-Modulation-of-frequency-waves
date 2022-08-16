#include<stdio.h>   //for input output
#include<stdlib.h>  //for system(clear);
#define pf printf
#define sf scanf
#define cs case     //macros
int FreqDev();      
int ModInd();
int CarSwi();       //declaration of functions
int main()
{   
    short int a;
    char b='1';
    pf("Welcome to Frequency Modulation Program !\n");
    while(b!='0')
    {
        pf("1. Frequency Deviation Δf\n2. Modulation Index μ (Requires Frequency Deviation Δf and Modulating Voltage Vm) \n3. Carrier Swing(Requires Frequency Deviation)");
        pf("\nEnter number to find value accordingly :\n");
        sf("%hd",&a);
        switch(a)                   // For various options
        {
            cs 1 : FreqDev();break;
            cs 2 : ModInd();break;
            cs 3 : CarSwi();break;
            default : pf("Invalid");    
        }  
    pf("\nEnter 0 to exit : ");     // To give an option to continue/exit the program
    sf("%c",&b);
    sf("%c",&b);                    // Doesn't take input if only 1 sf statement is present
    system("clear");     //clears window
    fflush;              //clears input buffer
    }
    return 0;

}

int FreqDev()        // Function to find Frequency Deviation
{
    short int d;
    pf("\nEnter :\n1. from Maximum and Mininum Frequency\n2. from Modulation Sensitivity Kf and Modulating Voltage Vm\n");
    sf("%hd",&d);
    if(d==1)
    {
        pf("Enter Maximum Frequency and Minimum Frequency(in MHz) : ");
        double fmx,fmn;
        sf("%lf %lf",&fmx,&fmn);
        if(fmx<fmn)
        pf("Invalid!");
        else
        pf("Frequency Deviation Δf= %.3lf MHz",(fmx-fmn));
        return 0;
    }
    else if(d==2)
    {
        pf("Enter Modulation Sensitivity Kf(in MHz/V) and Modulating Voltage Vm(in V) : ");
        double ms,vm;
        sf("%lf %lf",&ms,&vm);
        pf("Frequency Deviation Δf= %.3lf MHz",(ms*vm));
        return 0;
    }
    else 
    pf("Invalid!");
    return 0;
}
int ModInd()       // Function to find Modulation Index
{ 
    pf("Enter Frequency deviation Δf (in MHz) and Modulating Frequency fm(in MHz) : ");
    double fd,fm;
    sf("%lf %lf",&fd,&fm);
    if(fm==0)
    {
          pf("Invalid!");
    }
    else
    pf("Modulation Index = %.3lf",(fd/fm));
    return 0;
}
int CarSwi()        //  Function to  find Carrier Swing
{
    pf("Enter Frequency deviation Δf (in MHz) : ");
    double fd;
    sf("%lf",&fd);
    pf("Carrier Swing = %.3lf",(2*fd));
    return 0;
}

