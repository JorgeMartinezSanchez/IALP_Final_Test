#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main (){
	
	char gender;
	float BMI, weightM, heightM, weightIm, heightIm, heightImFt, IDW= 0;
	string MS;
	
	do{
		cout<<"Introduce your gender (f/m): ";
		cin>>gender;
		if (gender=='f'){
			do{
				cout<<"Choose your measurement system (Metric/Imperial): ";
				cin>>MS;
				if (MS=="Metric","metric"){
					
					cout<<"Introduce your height (meters): "; cin>>heightM;
					cout<<"Introduce your weight (kilograms): "; cin>>weightM;
					
					BMI = weightM / pow(heightM, 2);
					cout.precision(3);
					
					if (BMI<16.0){
						cout<<"Your BMI is "<<BMI<<". Damn, are you either an african kid or you are an extremely"<<endl;
						cout<<"anorexic bitch who needs a psychatrist?";
						
						IDW = 45.5 + 0.75 (heightM*100 - 150)
					    cout.precision(3);
					    cout<<"Your ideal weight is "<<IDW<<" Kg.";
					}
					else if (BMI<=18.4){
						cout<<"Your BMI is "<<BMI<<". Babe, you are not an obese deviantart whale, please go"<<endl;
						cout<<"please go eat some McDonald's or something";
						
						IDW = 45.5 + 0.75 (heightM*100 - 150)
					    cout.precision(3);
					    cout<<"Your ideal weight is "<<IDW<<" Kg.";
					}
					else if (BMI<=24.9){
						cout<<"Your BMI is "<<BMI<<". You got the ideal bod ma'am, keep it!";
					}
					else if (BMI<=29.9){
						cout<<"Your BMI is "<<BMI<<". You are a bit pudgy, but hey, many men like girls with"<<endl;
						cout<<"little rolls, it must be beautiful to hug someone like that.";
						
						IDW = 45.5 + 0.75 (heightM*100 - 150)
					    cout.precision(3);
					    cout<<"Anyways, your ideal weight is "<<IDW<<" Kg.";
					}
					else if (BMI<=34.9){
						cout<<"Your BMI is "<<BMI<<". Ok, you are kinda fatty, but you still got chance to get"<<endl;
						cout<<"normal";
						
						IDW = 45.5 + 0.75 (heightM*100 - 150)
					    cout.precision(3);
					    cout<<"Your ideal weight is "<<IDW<<" Kg.";
					}
					else if (BMI<=39.9){
						cout<<"Your BMI is "<<BMI<<". All right, you are obese, and don't go to the godamn"<<endl;
						cout<<"excuse of 'boo-hoo bodee posityve' dogshit, you don't want that, run 5 km for 10 minutes at least";
						
						IDW = 45.5 + 0.75 (heightM*100 - 150)
					    cout.precision(3);
					    cout<<"Your ideal weight is "<<IDW<<" Kg.";
					}
					else if (BMI>=40.0){
						cout<<"Your BMI is "<<BMI<<". JESUS CHRIST YOU NEED MEDICATION BECUASE YOU ARE MORBIDLY OBESE"<<endl;
						cout<<"PLEASE DO A WALK OR ABSOLUTELY ANY PHYSICAL ACTIVITY BECAUSE I DON'T THINK YOU WILL LIVE"<<endl;
						cout<<"UNTIL 30 YEARS OLD.";
						
						IDW = 45.5 + 0.75 (heightM*100 - 150)
					    cout.precision(3);
					    cout<<"Your ideal weight is "<<IDW<<" Kg.";
					}
				}
				else if (MS=="Imperial","imperial"){
					
					cout<<"Introduce your height: "; cin>>heightIm;
					cout<<"Introduce your weight: "; cin>>weightIm;
					
					BMI = 703 * (weightIm / heightIm^2)
					
				}
				else{
					cout<<"Damn, is there another unnecesary measurement system besides the american one?"<<endl;
					cout<<"Please choose an existent measurement system (Metric/Imperial): ";
					cin>>MS;
				}
			} while (true);
		}
		else if (gender=='m'){
			do{
				
				cout<<"Choose your measurement system (Metric/Imperial): ";
				cin>>MS;
				if (MS=="Metric","metric"){
					
					cout<<"Introduce your height: "; cin>>heightM;
					cout<<"Introduce your weight: "; cin>>weightM;
					
					BMI = weightM / heightM^2
					
					if (BMI<)
				}
				else if (MS=="Imperial","imperial"){
					
					cout<<"Introduce your height: "; cin>>heightIm;
					cout<<"Introduce your weight: "; cin>>weightIm;
					
					BMI = 703 * (weightIm / pow(height, 2))
					
				}
				else{
					cout<<"Damn, is there another unnecesary measurement system besides the american one?"<<endl;
					cout<<"Please choose an existent measurement system (Metric/Imperial): ";
					cin>>MS;
				}
				
			} while (true);
		}
		else {
			cout<<"There's only two genders you little blue dyed hair bitch."<<endl;
			cout<<"Please introduce an actual gender (f/m): ";
			cin>>gender;
		}
	} while (true);
	
	
	return 0;
}

