#include "tay_nguyen_campaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void mod_value(int arr[], int up_range){
  for (int i = 0; i< 17; i++){
    if (arr[i] > up_range) arr[i]= up_range;
    else if(arr[i] < 0) arr[i] = 0;
  }
}
void to_1d(int arr2d[5][5],int arr1d[]) {
  int num = 0;
  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
          arr1d[num++] = arr2d[i][j];
      }
  }
}

int maxin(int boso[], int len ){
  int max = boso[0];
  for(int i =1; i< len; i++){
    if (boso[i] > max) max = boso[i];
  }
  return max;
}
char toLower(char c) {
  if (c >= 'A' && c <= 'Z') {
      return c + 32;
  }
  return c;
}

char toUpper(char c) {
  if (c >= 'a' && c <= 'z') {
      return c - 32;
  }
  return c;
}

string reverse(string str){
  int end = str.size() - 1;
  string result = ""; 
  bool check = true;
  int start = 0;
  for(int i = end; i>= 0; i-- ){
      result.push_back(toLower(str[i]));
      if(check){
          result[start] = toUpper(result[start]);
          check = false;
      }
      else if(str[i] == ' ') check = true;
      start++;
  }
  return result;
}
string Caesar_Cipher(string ques)
    {char data1[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
         data2[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for (char &c : ques)
            {for (int i = 0; i< 26; i++){
                    if (c >= 'A' && c <= 'Z' && c == data1[i])   { c = data1[(i  - 22 + 26) % 26];}
                    else if(c >= 'a' && c <= 'z'&& c == data2[i]) {c = data2[(i  - 22 + 26) % 26];}
                    else continue;
                    break;
            
    }
}
return ques;
}


const int MAX_LINES = 5;         
const int MAX_LINE_LENGTH = 100;

// Task 0: Read input file
bool readFile(
    const string &filename,
    int LF1[], int LF2[],
    int &EXP1, int &EXP2,
    int &T1, int &T2, int &E)
{
  char data[MAX_LINES][MAX_LINE_LENGTH];
  int numLines = 0;

  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    return false;
  }

  while (numLines < MAX_LINES && ifs.getline(data[numLines], MAX_LINE_LENGTH))
  {
    numLines++;
  }
  ifs.close();

  if (numLines < MAX_LINES)
  {
    return false;
  }

   // Parse first line into LF1
   string line1(data[0]);
   line1 = line1.substr(1, line1.size() - 2); // Remove brackets
   stringstream ss1(line1);
   string token;
   int index = 0;
   while (getline(ss1, token, ','))
   {
     LF1[index++] = stoi(token);
   }
 
   // Parse second line into LF2
   string line2(data[1]);
   line2 = line2.substr(1, line2.size() - 2); // Remove brackets
   stringstream ss2(line2);
   index = 0;
   while (getline(ss2, token, ','))
   {
     LF2[index++] = stoi(token);
   }

  // Parse third line for EXP1 and EXP2
  stringstream ss3(data[2]);
  ss3 >> EXP1 >> EXP2;

  // Parse fourth line for T1 and T2
  stringstream ss4(data[3]);
  ss4 >> T1 >> T2;

  // Parse fifth line for E
  stringstream ss5(data[4]);
  ss5 >> E;

  return true;
}

// Task 1
int gatherForces(int LF1[], int LF2[])
{
  // TODO: Implement this function
  int trongso[] = {1,2,3,4,5,7,8,9,10,12,15,18,20,30,40,50,70};
  int sum = 0;
  for (int i = 0; i< 17; i++){
    sum += LF1[i] * trongso[i] + LF2[i] * trongso[i];
  }
  return sum;
}

// Task 2
string determineRightTarget(const string &target)
{
  // TODO: Implement this function
  string muctieu[8] = {" ", " ", "  ","Buon Ma Thuoc", "Duc Lap", "Dak Lak", "National Route 21", "National Route 14"};
  int so = 0;
  bool number_ing = false;
  int store[100], count = 0;

  for (char c : target) {
      if (isdigit(c)) {
          so = so * 10 + (c - '0');
          number_ing = true;
      } 
      else if (number_ing) { 
          store[count++] = so;
          so = 0;
          number_ing = false;
      }
  }
      if (number_ing) {
          store[count++] = so;
      }
  for (int i = 0; i < count; i++) {
    cout << store[i] << " ";
}
  cout<<count;
  if ( count  == 1){ return muctieu[store[0]];}
  else if ( count == 2){return muctieu[((store[0] + store[1]) % 5) + 3];}
  else if (count == 3 ){return muctieu[(maxin(store, count)%5)+3];}
  else return "INVALID";
    } 


string decodeTarget(const string &message, int EXP1, int EXP2)
{
  // TODO: Implement this function
  string muctieu[5] = {"Buon Ma Thuoc", "Duc Lap", "Dak Lak", "National Route 21", "National Route 14"};
  if ( EXP1 >= 300 && EXP2 >= 300){
    for (string check : muctieu){if(check == Caesar_Cipher(message)) { return check; }}
  }
  if (EXP1 < 300 || EXP2<300){
    for (string check : muctieu){if(check == reverse(message)) { return check; }}
  }
  return "INVALID";
}
  

// Task 3
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E)
{
  // TODO: Implement this function
  
  if (E>=1 && E<=9){
    T1 = ceil(T1 - ((float)E/100)*T1);
    T2 = ceil(T2 - ((((float)E*0.5))/100) * T2);
  }
  else if ( E >= 10 && E<= 29){
    int addin = E*50;
    T1 +=addin;
    T2 +=addin;
  }
  else if (E>=30 && E<= 59){
    T1 =ceil( T1 + ((((float)E*0.5))/100)*T1);
    T2 =ceil( T2 + ((((float)E*0.2))/100)*T2);
  }
  else if (E=0){
    float delta_T1 =ceil( ((float)LF1/((float)LF1+(float)LF2)*((float)T1+(float)T2))*(1+((float)EXP1+(float)EXP2)/100)),
        delta_T2 =ceil( (T1+T2)-delta_T1);
    T1 += delta_T1;
    T2 += delta_T2;
  }
  if(T1 >3000){T1 = 3000;}
  if(T2 > 3000){T2 = 3000;}

}

// Task 4
int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10])
  {
    // TODO: Implement this function
    double sum = (LF1+LF2)+5*(EXP1+EXP2)+2*(T1+T2);
    for (int i = 0; i< 10; i++){
      for (int j = 0; j<10; j++){
        if(i % 2 != 0){
          sum -= battleField[i][j]*3/2;
        }
        else sum-= battleField[i][j]*2/3;
      }
    }
  
    return ceil(sum);
  }


// Task 5
int resupply(int shortfall, int supply[5][5])
{
  // TODO: Implement this function
  int arr[25];
  to_1d(supply,arr);
  int sum = 0;
  int minsum = 2147483647;
  int stor[5];
  for (int i = 0; i < 25 - 4; i++) {
    for (int j = i + 1; j < 25 - 3; j++) {
        for (int k = j + 1; k < 25 - 2; k++) {
            for (int l = k + 1; l < 25 - 1; l++) {
                for (int m = l + 1; m < 25; m++) {
                    sum = arr[i] + arr[j] + arr[k] + arr[l] + arr[m];
                    stor[0] = i; stor[1] = j;stor[2] = k;stor[3] = l;stor[4] = m;
                    if (sum > shortfall && sum < minsum) {
                      
                        minsum = sum;
                     
                    }
                }
            }
        }
    }
}  
   return minsum;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
