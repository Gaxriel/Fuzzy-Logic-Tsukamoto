#define MAX 1000

#include <iostream>
#include <sstream>
#include <stdlib.h>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
#include <queue>
using namespace std;
int jmlVar=0;
float maxVar[MAX];
float minVar[MAX];
float permaxVar[MAX];
float perminVar[MAX];
float currVar[MAX];
string namaVar[MAX];
int switchResVar = 0;
int searchVar;
string dataKonj[MAX][MAX];
string dataKonjReal[MAX][MAX];
int theRules[MAX];
string theBackUpRules[MAX];
float dataValueDecimal[MAX];
float itisx[MAX];
int theValueofData[MAX];

float percentageMax(float x, float b, float a){
	float result = (x-a)/(b-a);
	return result;
}

float percentageMin(float x, float b, float a){
	float result = (b-x)/(b-a);
	return result;
}

void startingdataKonjReal(){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			dataKonjReal[i][j]="__";
			dataKonj[i][j]="__";
		}	
	}
}

void initialAllComponents(){
		string tempSwitch;
	
	cout << "Jumlah Variabel Sukamoto: ";
	cin >> jmlVar;
	
	
	for(int i=0;i<jmlVar;i++){
		cout << "Nama Var ke - " << (i+1) << ": ";
		cin >> namaVar[i];
		//cout << i << " - " << switchResVar << endl << endl;
		if(switchResVar==0){
			tempSwitch = "";	
			while(tempSwitch!="y"){
				//cout << tempSwitch << endl << endl;
				cout << "Apakah variabel " << namaVar[i] << " ini yang ingin anda cari?" << endl;
				cout << "[y/n]: ";
				cin >> tempSwitch;
				if(tempSwitch == "y"){
					switchResVar = 1;
					searchVar=i;
					tempSwitch = "y";
				}else if(tempSwitch=="n"){
					tempSwitch = "y";
				}	
			}
		}
		
	}
	
	if(switchResVar==0){
		cout << "Tidak dapat diproses..." << endl;
		cout << "Ulangi kembali" << endl;
		initialAllComponents();
	}
}

void initialMaxVar(){
	cout << endl << endl;
	cout << "Variabel Maximal" << endl;
	for(int i=0;i<jmlVar;i++){
		
		cout << "Variabel " << namaVar[i] << endl;
		cout << "Max Value Variabel " << namaVar[i] << ": ";
		cin >> maxVar[i];
	}
}

void initialMinVar(){
	cout << endl << endl;
	cout << "Variabel Minimal" << endl;	
	for(int i=0;i<jmlVar;i++){
		
		cout << "Variabel " << namaVar[i] << endl;
		cout << "Min Value Variabel " << namaVar[i] << ": ";
		cin >> minVar[i];
	}
}

void initialCurrVar(){
	cout << endl << endl;
	cout << "Current Variabel" << endl;	
	for(int i=0;i<jmlVar;i++){
		if(i==searchVar){
			cout << "Variabel ini " << namaVar[i] << " akan dicari nilainya." << endl << endl;
		}else{
			cout << "Variabel " << namaVar[i] << endl;
			cout << "Current Value Variabel " << namaVar[i] << ": ";
			cin >> currVar[i];
			cout << endl << endl;
		}
		
	}
}

void initialPercentageVar(){
	
}

void showInformationDetail(){
	cout << "Information Detail" << endl;
	cout << "Jumlah Variabel: " << jmlVar << endl;
	for(int i=0;i<jmlVar;i++){
		if(searchVar!=i){
		cout << "================" << endl;
		cout << "Variabel " << namaVar[i] << endl;
		cout << "================" << endl;
		cout << "Maximal Variabel: " << maxVar[i] << endl;
		cout << "Maximal Variabel: " << minVar[i] << endl;
		cout << "Current Variabel: " << currVar[i] << endl;
		cout << "Percentage Maximal Variabel: " << percentageMax(currVar[i], maxVar[i], minVar[i]) << endl;
		cout << "Percentage Minimal Variabel: " << percentageMin(currVar[i], maxVar[i], minVar[i]) << endl;
		cout << endl << endl;
		
		
		permaxVar[i] = percentageMax(currVar[i], maxVar[i], minVar[i]);
		perminVar[i] = percentageMin(currVar[i], maxVar[i], minVar[i]);
		}else{
		cout << "================" << endl;
		cout << "Variabel " << namaVar[i] << endl;
		cout << "================" << endl;
		cout << "Maximal Variabel: " << maxVar[i] << endl;
		cout << "Maximal Variabel: " << minVar[i] << endl;
		cout << "Current Variabel: [Nilai yang dicari]" << endl;
		cout << "Formula Percentage Maximal Variabel: (" << "x-" << minVar[i] <<")/(" << maxVar[i] << "-" << minVar[i] << ")" << endl;
		cout << "Formula Percentage Minimal Variabel: (" << maxVar[i] << "-" << "x)/(" << maxVar[i] << "-" << minVar[i] << ")" << endl;
		
		cout << endl << endl;

		}
	}
}

void countkonjungsiVar(){
	for(int i=0;i<jmlVar;i++){
		for(int j=0;j<jmlVar;j++){
			if(searchVar!=i || searchVar!=j){
				
			}
		}	
	}
}

queue<string> ReverseQueue(queue<string> q) {
	queue<string> newReverse;
    while(!q.empty())
			{
			    string w = q.front();
			    newReverse.push(w);
			    q.pop();
			}
    return newReverse;
}

string test;
string ss[MAX];
queue<string> historyofss;
queue<string> temphistoryofss;

void insertVartoss(){
	for(int i=0;i<jmlVar;i++){
		if(i==searchVar){
			ss[i]="$";
		}else{
			ss[i]=namaVar[i];
			
		}
		
		if(i==(jmlVar-1)){
			
			if(i==searchVar){
				test=namaVar[i-1];
			}else{
				test=namaVar[i];
			}
		}
	}
}
int tempRow=0;

void coba(string abj, int currAr){
	string temssp;
	
	for(int i=0;i<2;i++){
		//cout << tempRow;
		//cout << abj << i;
		temssp = SSTR(i);
		dataKonj[tempRow][currAr]=abj+""+temssp;
		//cout << endl << "dataKonj-" << tempRow << currAr << ": " << abj+temssp << endl;
		
		
		if(abj==test){
			//cout << endl;
			tempRow=tempRow+1;
			
			//temphistoryofss=ReverseQueue(historyofss);
			while(!historyofss.empty())
			{
			    string w = historyofss.front();
			    //cout << w;
			    //dataKonj[i][currAr]=w;
			    historyofss.pop();
			}
			
			
		}else{
			temssp = SSTR(i);
			historyofss.push(abj+temssp);
			dataKonj[tempRow][currAr+1]=abj+temssp;
			//cout << endl << "dataKonj-" << tempRow << currAr+1 << ": " << abj+temssp << endl;
			coba(ss[currAr+1], currAr+1);	
		}
		
	}
	
	//cout << endl  << endl;
	
}


void dataKonjtoArray(){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			
			if(dataKonj[i][j]=="" || dataKonj[i][j]=="__"){
				if(j<=(jmlVar-1)){
					//cout << "**";
					dataKonjReal[i][j]=dataKonjReal[i-1][j];
				}else{
					//cout << "^^";
				}
				
			}else{
				//cout << dataKonj[i][j];
				dataKonjReal[i][j]=dataKonj[i][j];
			}
		}
		
		//cout << endl;
	}
	
	int jumlahBaris=1;
	
	for(int i=0;i<jmlVar;i++){
		jumlahBaris = jumlahBaris * 2;
	}
	
	for(int i=0;i<jmlVar;i++){
		if(dataKonjReal[0][i]=="$1" || dataKonjReal[0][i]=="$0"){
			
			
			for(int k=0;k<jumlahBaris;k++){
				for(int j=i;j<(jmlVar-1);j++){
					dataKonjReal[k][j]=dataKonjReal[k][j+1];
				}
				
				dataKonjReal[k][jmlVar-1]="";
			}
			
			
		}
	}
	
	
	
}

void clearMultipleDataKonj(int noBaris){
	//cout << "clear barus: " << noBaris << endl;
	int jumlahBaris=1;
	
	for(int i=0;i<jmlVar;i++){
		jumlahBaris = jumlahBaris * 2;
	}
	
	for(int i=noBaris;i<jumlahBaris;i++){
		for(int j=0;j<(jmlVar-1);j++){
			dataKonjReal[i][j]=dataKonjReal[i+1][j];
		}
	}
}

	void printResultdataKonj(){
	int jumlahBarisReal=1;
	
	for(int i=0;i<(jmlVar-1);i++){
		jumlahBarisReal = jumlahBarisReal * 2;
	}

	for(int i=0;i<jumlahBarisReal;i++){
		for(int j=0;j<(jmlVar-1);j++){
			//cout << "[" << dataKonjReal[i][j] << "]";
			if(dataKonjReal[i][j]=="$1"){
				
			}else if(dataKonjReal[i][j]=="$0"){
			}
		}
		//cout << endl;
	}
}

int checkValueinNamaVarArray(string nama){
	for(int i=0;i<jmlVar;i++){
		if(namaVar[i]==nama){
			return i;
		}
	}
}
bool XOR(bool a, bool b)
{
    return (a + b) % 2;
}

void declareTheRules(){
	cout << "The Rules" << endl;

	string tempInput="";
	string tempStringData="";
	string tempStringKetData="";
	
	string tempValueData="";
	
	int jumlahBarisReal=1;
	for(int i=0;i<(jmlVar-1);i++){
		jumlahBarisReal = jumlahBarisReal * 2;
	}
	
	
	for(int i=0;i<jumlahBarisReal;i++){
		
		
		tempStringData="";
		tempStringKetData="";
		for(int j=0;j<(jmlVar-1);j++){
			
			tempStringData = dataKonjReal[i][j].substr(0,dataKonjReal[i][j].length()-1);
			tempStringKetData = dataKonjReal[i][j].substr(dataKonjReal[i][j].length()-1,dataKonjReal[i][j].length());
			
			
			
			if(tempStringKetData=="0"){
				tempValueData = SSTR(perminVar[checkValueinNamaVarArray(tempStringData)]);
				cout << "[" << tempStringData << "- Down]";
			}else if(tempStringKetData=="1"){
				tempValueData = SSTR(permaxVar[checkValueinNamaVarArray(tempStringData)]);
				cout << "[" << tempStringData << "- Up]";
			}
			
			//cout << tempValueData << " ";
			
			if(j==0){
			theBackUpRules[i]=tempStringData+tempStringKetData;	
			}else{
			theBackUpRules[i]=theBackUpRules[i]+tempStringData+tempStringKetData;	
			}
			
			
		}
	
		cout << ": (0 Down, 1 Up): ";
		cin >> theRules[i];
		tempInput=theRules[i];
		cout << endl;
	}
}

void countTheTableDetail(){
	cout << endl <<  "Perhitungan" << endl;
	string tempStringData="";
	string tempStringKetData="";

	
	float tempValueData;
	float smallestValueData;
	string smallestKetData;
	int jumlahBarisReal=1;
	for(int i=0;i<(jmlVar-1);i++){
		jumlahBarisReal = jumlahBarisReal * 2;
	}
	
	for(int i=0;i<jumlahBarisReal;i++){
		smallestValueData=0;
		tempValueData=0;
		tempStringData="";
		tempStringKetData="";
		smallestKetData="";
		for(int j=0;j<(jmlVar-1);j++){
			tempStringData = dataKonjReal[i][j].substr(0,dataKonjReal[i][j].length()-1);
			tempStringKetData = dataKonjReal[i][j].substr(dataKonjReal[i][j].length()-1,dataKonjReal[i][j].length());
			if(tempStringKetData=="0"){
				tempValueData = perminVar[checkValueinNamaVarArray(tempStringData)];
			}else if(tempStringKetData=="1"){
				tempValueData = permaxVar[checkValueinNamaVarArray(tempStringData)];
			}
			//cout << "[" << tempValueData << "]";			
			if(j==0){
				smallestValueData = tempValueData;
				smallestKetData = tempStringKetData;
			}else{
				if(tempValueData<smallestValueData){
					smallestValueData = tempValueData;
					smallestKetData = tempStringKetData;
				}
			}
		}
	
		//cout << ": ";
		//cout << smallestValueData;
		dataValueDecimal[i]=smallestValueData;
		
		//cout << endl << "$$$$$" << theRules[i] << "$$$$$" << endl;
		if(theRules[i]==1){
			theValueofData[i]=(smallestValueData*(maxVar[searchVar]-minVar[searchVar]))+minVar[searchVar];
			cout << endl << "(" << smallestValueData << "*(" << maxVar[searchVar] << "-" << minVar[searchVar] << "))+" << minVar[searchVar] << " = ";
			cout << " " << theValueofData[i] << endl;
		}else if(theRules[i]==0){
			theValueofData[i]=maxVar[searchVar]-(smallestValueData*(maxVar[searchVar]-minVar[searchVar]));
			cout << endl << maxVar[searchVar] << "-(" << smallestValueData << "*(" << maxVar[searchVar] << "-" << minVar[searchVar] << "))" << " = ";
			cout << " " << theValueofData[i] << endl;
		}
		
		
		cout << endl;
	}
	
	
}

void theResult(){
	int jumlahBarisReal=1;
	float totalatas=0;
	float totalbawah=0;
	float result;
	for(int i=0;i<(jmlVar-1);i++){
		jumlahBarisReal = jumlahBarisReal * 2;
	}
	
	cout << "Perhitungan Total Atas: ";
	for(int i=0;i<jumlahBarisReal;i++){
		totalatas=totalatas+(theValueofData[i]*dataValueDecimal[i]);
		if(i==jumlahBarisReal-1){
			cout << "(" << theValueofData[i] << " * " << dataValueDecimal[i] << ")";
		}else{
			cout << "(" << theValueofData[i] << " * " << dataValueDecimal[i] << ") + ";
		}
	}
	cout << endl << endl;
	cout << "Perhitungan Total Bawah: ";
	for(int i=0;i<jumlahBarisReal;i++){
		totalbawah=totalbawah+dataValueDecimal[i];
		
		if(i==jumlahBarisReal-1){
			cout << dataValueDecimal[i] << " ";
		}else{
			cout << dataValueDecimal[i] << " + ";
		}
		
	}
	result=totalatas/totalbawah;
	cout << endl << endl;
	cout << "Hasil Total Atas: " << totalatas << endl;
	cout << "Hasil Total Bawah: " << totalbawah << endl;
	cout << "Hasil Akhir (Total Atas/Total Bawah): " << result << endl << endl;
}

void showtheBackUpRules(){
	int jumlahBarisReal=1;
	for(int i=0;i<(jmlVar-1);i++){
		jumlahBarisReal = jumlahBarisReal * 2;
	}
	
	
	for(int i=0;i<jumlahBarisReal;i++){
		//cout << theBackUpRules[i] << endl;		
	}
}

void showtheRules(){
	int jumlahBarisReal=1;
	for(int i=0;i<(jmlVar-1);i++){
		jumlahBarisReal = jumlahBarisReal * 2;
	}
	
	//cout << endl << "The Back Up Rules" << endl;
	for(int i=0;i<jumlahBarisReal;i++){
		//cout << theRules[i] << endl;		
	}
}



void checkclearMultipleDataKonj(){
	string tempData = "";
	string tempData2 = "";
	int jumlahBaris=1;
	
	for(int i=0;i<jmlVar;i++){
		jumlahBaris = jumlahBaris * 2;
	}
	
	//cout << "CLEAR MULTIPLE" << endl;
	for(int i=0;i<jumlahBaris;i++){
		//cout << "TD: ";
		for(int j=0;j<(jmlVar-1);j++){
			tempData = tempData + dataKonjReal[i][j];
				 //cout << tempData;
			}
			
				for(int k=0;k<jumlahBaris;k++){
					//cout << "K: " << i << " - " << k << endl;
					if(k!=i){
						//cout << "TD2: ";
						for(int l=0;l<(jmlVar-1);l++){
							tempData2 = tempData2 + dataKonjReal[k][l];
							//cout << tempData2;
						}
						
						//cout << "L: " << tempData << " - " << tempData2 << endl;
						if(tempData2==tempData){
							
							//cout << "Clear: " << tempData << " - " << tempData2 << endl;
							clearMultipleDataKonj(i);
							//printResultdataKonj();
						}
						
						//cout << endl;
						tempData2="";
					}
				}
			
		
		
		//cout << endl;
		tempData="";
	}
}


main(){
	
	startingdataKonjReal();
	initialAllComponents();
	system("cls");
	initialMaxVar();
	initialMinVar();
	system("cls");
	initialCurrVar();
	showInformationDetail();
	insertVartoss();
	system("cls");
	
	//mulaiKombinasiKonjungsi
	coba(ss[0],0);
	
	dataKonjtoArray();
	
	for(int i=0;i<(jmlVar-1);i++){	
		checkclearMultipleDataKonj();
	}
	
	
	printResultdataKonj();
	declareTheRules();
	
	showtheBackUpRules();
	showtheRules();
	
	system("cls");
	countTheTableDetail();
	theResult();

		
		
	
	
	//cout << ss[0];

	
	
	
	}

	
	

