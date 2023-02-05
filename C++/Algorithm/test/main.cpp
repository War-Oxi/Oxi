#include<bits/stdc++.h>
using namespace std;

char s[104]={0,};

int main(){
	ios_base::sync_with_stdio(false);


	int i=0;
	scanf("%s",s);
	int size=0;

	for(i=0;s[i]!=0;i++){
		size++;
	}


	for(i=0;i<size;i++){
		if(s[i] == 'c' && s[i+1] == '=')
			size--;
		else if(s[i] == 'c' && s[i+1] == '-')
			size--;
		else if(s[i] == 'd' && s[i+1] == '-')
			size--;
		else if(s[i] == 'l' && s[i+1] == 'j')
			size--;
		else if(s[i] == 'n' && s[i+1] == 'j')
			size--;
		else if(s[i] == 's' && s[i+1] == '=')
			size--;
		else if(s[i] == 'd' && s[i+1] == 'z' && s[i+2] == '=')
			size -= 2;
	    else if(s[i] != 'd' && s[i+1] == 'z' && s[i+2] == '=' )
			size--;
	}

	printf("%d",size);
	return 0;
}