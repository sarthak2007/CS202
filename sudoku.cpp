#include<bits/stdc++.h>
using namespace std;
int cnt=0;
string encoding(int a[9][9]){
	string sat;
	cnt=0;
	int b,i=0,j,k,x,y,p,q,z;
	//each cell has a number
	//start
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(a[i][j]==0){
				b=81*i + 9*j + 1;
				for(k=0;k<9;k++){
					sat = sat + to_string(b) + " " ;
					b++;
				}
				sat+="0\n";
				cnt++;
			}
		}
	}
	//end
	//each cell has exactly one number
	//start
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(a[i][j]==0){
				for(x=0;x<9;x++){
					for(y=x+1;y<9;y++){
						b=81*i + 9*j + 1;
						sat+= "-" + to_string(b+x) + " -" + to_string(b+y) + " 0\n";
						cnt++;
					}
				}
			}
		}
	}
	//end
	//Row constraint
	//start
	vector<int> already;
	int flag=0;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(a[i][j]!=0)	already.push_back(a[i][j]);
		}
		for(j=1;j<=9;j++){
			flag=0;
			for(k=0;k<already.size();k++){
				if(already[k]==j){
					flag=1;
					break;
				}
			}
			if(flag==1){
				for(x=0;x<9;x++){
					if(a[i][x]==0){
						b=81*i + 9*x + j;
						sat+= "-" + to_string(b) + " 0\n";
						cnt++;
					}
				}
			}
			else{
				for(x=0;x<9;x++){
					for(y=x+1;y<9;y++){
						if(a[i][x]==0 && a[i][y]==0){
							b=81*i + j;
							sat+= "-" + to_string(b+9*x) + " -" + to_string(b+9*y) + " 0\n";
							cnt++;
						}
					}
				}
			}
		}
		already.clear();
	}
	//end
	//Column constraint
	//start
	vector<int> already1;
	int flag1=0;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(a[j][i]!=0)	already1.push_back(a[j][i]);
		}
		for(j=1;j<=9;j++){
			flag1=0;
			for(k=0;k<already1.size();k++){
				if(already1[k]==j){
					flag1=1;
					break;
				}
			}
			if(flag1==1){
				for(x=0;x<9;x++){
					if(a[x][i]==0){
						b=81*x + 9*i + j;
						sat+= "-" + to_string(b) + " 0\n";
						cnt++;
					}
				}
			}
			else{
				for(x=0;x<9;x++){
					for(y=x+1;y<9;y++){
						if(a[x][i]==0 && a[y][i]==0){
							b=9*i + j;
							sat+= "-" + to_string(b+81*x) + " -" + to_string(b+81*y) + " 0\n";
							cnt++;
						}
					}
				}
			}
		}
		already1.clear();
	}
	//end
	//Main diagonal constraint
	//start
	vector<int> already2;
	int flag2=0;
	for(j=0;j<9;j++){
		if(a[j][j]!=0)	already2.push_back(a[j][j]);
	}
	for(j=1;j<=9;j++){
		flag2=0;
		for(k=0;k<already2.size();k++){
			if(already2[k]==j){
				flag2=1;
				break;
			}
		}
		if(flag2==1){
			for(x=0;x<9;x++){
				if(a[x][x]==0){
					b=81*x + 9*x + j;
					sat+= "-" + to_string(b) + " 0\n";
					cnt++;
				}
			}
		}
		else{
			for(x=0;x<9;x++){
				for(y=x+1;y<9;y++){
					if(a[x][x]==0 && a[y][y]==0){
						b=j;
						sat+= "-" + to_string(b+90*x) + " -" + to_string(b+90*y) + " 0\n";
						cnt++;
					}
				}
			}
		}
	}
	already2.clear();
	//end
	//Second main diagonal constraint
	//start
	vector<int> already4;
	int flag4=0;
	for(j=0;j<9;j++){
		if(a[j][8-j]!=0)	already4.push_back(a[j][8-j]);
	}
	for(j=1;j<=9;j++){
		flag4=0;
		for(k=0;k<already4.size();k++){
			if(already4[k]==j){
				flag4=1;
				break;
			}
		}
		if(flag4==1){
			for(x=0;x<9;x++){
				if(a[x][8-x]==0){
					b=81*x + 9*(8-x) + j;
					sat+= "-" + to_string(b) + " 0\n";
					cnt++;
				}
			}
		}
		else{
			for(x=0;x<9;x++){
				for(y=x+1;y<9;y++){
					if(a[x][8-x]==0 && a[y][8-y]==0){
						b=j;
						sat+= "-" + to_string(b+81*x+9*(8-x)) + " -" + to_string(b+81*y+9*(8-y)) + " 0\n";
						cnt++;
					}
				}
			}
		}
	}
	already4.clear();
	//end
	//3*3 Box constraint
	//start
	vector<int> already3;
	int flag3=0;
	for(i=0;i<9;i=i+3){
		for(j=0;j<9;j=j+3){
			for(x=i;x<i+3;x++){
				for(y=j;y<j+3;y++){
					if(a[x][y]!=0)	already3.push_back(a[x][y]);
				}
			}
			for(k=1;k<=9;k++){
				flag3=0;
				for(z=0;z<already3.size();z++){
					if(already3[z]==k){
						flag3=1;
						break;
					}
				}
				if(flag3==1){
					for(x=i;x<i+3;x++){
						for(y=j;y<j+3;y++){
							if(a[x][y]==0){
								b=81*x + 9*y + k;
								sat+= "-" + to_string(b) + " 0\n";
								cnt++;
							}
						}
					}
				}
				else{
					for(x=i;x<i+3;x++){
						for(y=j;y<j+3;y++){
							p=x;
							for(q=y+1;q<j+3;q++){
								if(a[x][y]==0 && a[p][q]==0){
									b=k;
									sat+= "-" + to_string(b+81*x+9*y) + " -" + to_string(b+81*p+9*q) + " 0\n";
									cnt++;
								}									
							}
							for(p=x+1;p<i+3;p++){
								for(q=j;q<j+3;q++){
									if(a[x][y]==0 && a[p][q]==0){
										b=k;
										sat+= "-" + to_string(b+81*x+9*y) + " -" + to_string(b+81*p+9*q) + " 0\n";
										cnt++;
									}									
								}
							}
							
						}
					}
				}
			}
			already3.clear();
		}
	}
	//end
	return sat;
}
void solve(int a[9][9]){
	cnt=0;
	int i=0,j;
	string sat;
	sat=encoding(a);
	sat="p cnf 729 " + to_string(cnt) + "\n" + sat;
	ofstream f("satinput.txt");
	f << sat;
	f.close();
	ofstream fa("satoutput.txt");
	fa.close();
	system("minisat satinput.txt satoutput.txt");
	ifstream ans;
	string answer;
	ans.open("satoutput.txt");
	getline(ans,answer);
	int row,col,answer1,digit;
	if(answer=="SAT"){
		getline(ans,answer);
		string number="";
		for(i=0;i<answer.length();i++){
			if(answer[i]==' '){
				if(number[0]!='-'){
					answer1=stoi(number);
					digit=answer1%9;
					if(digit==0)	digit=9;
					answer1= (answer1 - digit)/9;
					col=answer1%9;
					row=(answer1-col)/9;
					a[row][col]=digit;
				}
				number="";
			}
			else{
				number+=answer[i];
			}
		}
	}
	ans.close();
}
int unique(int a[9][9]){
	cnt=0;
	int i,j,answer1;
	string sat,sat1;
	sat=encoding(a);
	sat1="p cnf 729 " + to_string(cnt) + "\n" + sat;
	ofstream f("satinput.txt");
	f << sat1;
	f.close();
	ofstream fa("satoutput.txt");
	fa.close();
	system("minisat satinput.txt satoutput.txt");
	ifstream ans;
	string answer;
	ans.open("satoutput.txt");
	getline(ans,answer);
	getline(ans,answer);
	ans.close();
	string number="",lastline="";
	vector<int> b;
	int cnt1=0,flag=0;
	for(i=0;i<answer.length();i++){
		if(answer[i]==' '){
			answer1=stoi(number);
			answer1*=-1;
			b.push_back(answer1),cnt1++;
			if(cnt1==9){
				cnt1=0,flag=0;
				for(j=0;j<9;j++){
					if(b[j]<0){
						flag=1;break;
					}
				}
				if(flag==1){
					for(j=0;j<9;j++){
						lastline+=to_string(b[j])+" ";	
					}
				}
				b.clear();
			}
			number="";
		}
		else{
			number+=answer[i];
		}
	}
	lastline+="0";
	sat1="p cnf 729 " + to_string(cnt+1) + "\n" + sat + lastline;
	ofstream g("satinput.txt");
	g << sat1;
	g.close();
	system("minisat satinput.txt satoutput.txt");
	ifstream ans1;
	ans1.open("satoutput.txt");
	getline(ans1,answer);
	ans1.close();
	if(answer=="UNSAT")	return 1;
	else return 0;
}
void generate(){
	int a[9][9],i,j,digit,flag=0,x,y,row,col;
	cnt=0;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++)
			a[i][j]=0;
	}
	srand(time(NULL));
	i=rand()%9;
	j=rand()%9;
	digit=1+rand()%9;
	a[i][j]=digit;
	solve(a);
	while(1){
		srand(time(NULL));
		row=rand()%9,col=rand()%9;
		while(a[row][col]==0){
			row=rand()%9,col=rand()%9;
		}
		digit=a[row][col];
		a[row][col]=0;
		if(unique(a)!=1){
			a[row][col]=digit;
			flag=0;
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					if(a[i][j]!=0){
						row=i,col=j,digit=a[i][j];
						a[i][j]=0;
						if(unique(a)==1){
							flag=1;break;
						}
						a[i][j]=digit;
					}
				}
				if(flag==1)	break;
			}
			if(flag==0)	break;
		}
	}
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(a[i][j]==0)	cout<<".";
			else	
				cout << a[i][j];
		}
		cout << endl;
	}
}
int main(){
	int input;
	cout<< "Press 1 to get solved sudoku from the given text file\n and 2 to generate a sudoku."<<endl;
	cin>>input;
	if(input==1){
		ifstream file;
		string line;
		int a[9][9],i=0,j;
		file.open("sudoku.txt");
		while(file){
			getline(file,line);
			for(j=0;j<9;j++){
				if(line[j]=='.')	a[i][j]=0;
				else a[i][j]=(int)line[j]-48;
			}
			i++;
			if(i==10)	break;
		}
		file.close();
		solve(a);
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				cout<<a[i][j];
			cout<<endl;
		}
	}
	else if(input==2)
		generate();
	else
		cout<< "Please provide correct input."<<endl;
	return 0;
}