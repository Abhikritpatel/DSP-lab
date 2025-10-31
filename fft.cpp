#include <bits/stdc++.h>
#include<complex>
#include<cmath>

#define complex_d complex<double>
#define pi 3.14159 

using namespace std;

int main() {
    
	int n=15;
	cout << "--- Calculating 15-Point FFT ---" << endl;
	
	cout << "Enter 15 real signal values (e.g., 1 0 0...):" << endl;

	vector<double> v(n);
	
	// taking the input of signal in a 1D array
	for(int i=0;i<n;i++) cin>>v[i];
	
	// Mapping this signal into L*M 2D array
	int l=5,m=3;
	vector<vector<complex_d>> x(l,vector<complex_d>(m));
	int cnt=0;
	for(int i=0;i<m;i++){
	    for(int j=0;j<l;j++){
	        x[j][i]=v[cnt];
	        cnt++;
	      
	    }
	   
	}
	// see the 5*3 2D Mapping
// 	for(int i=0;i<l;i++){
// 	    for(int j=0;j<m;j++){
// 	        cout<<x[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
	
	vector<vector<complex_d>> grid1(l,vector<complex_d>(m));
	// compute 3 point dft of each row
	for(int i=0;i<l;i++){
	    for(int j=0;j<m;j++){
	        complex_d sum={0,0};
	        
	        for(int a=0;a<m;a++){
	            complex_d sample=x[i][a];
	            double angle=(-2*pi*a*j)/m;
	            complex_d W=polar(1.0,angle);
	            sum+=sample*W;
	        }
	        grid1[i][j]=sum;
	    }
	}
// 		for(int i=0;i<l;i++){
// 	    for(int j=0;j<m;j++){
// 	        cout<<grid1[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
	
	// now multiplying the obtained grid1 with the twiddle factor
	vector<vector<complex_d>> grid2(l,vector<complex_d>(m));
	for(int i=0;i<l;i++){
	    for(int j=0;j<m;j++){
	        double angle=(-2*pi*j*i)/n;
	        complex_d W= polar(1.0,angle);
	        grid2[i][j]=grid1[i][j]*W;
	    }
	}
	
// 	cout<<endl;
// 		for(int i=0;i<l;i++){
// 	    for(int j=0;j<m;j++){
// 	        cout<<grid2[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
	
	// now computing the 5 point DFT of grid2
	vector<vector<complex_d>> grid3(l,vector<complex_d>(m));
	for(int i=0;i<m;i++){
	    
	    for(int j=0;j<l;j++){
	        complex_d sum={0,0};
	        for(int a=0;a<l;a++){
	            complex_d sample=grid2[a][i];
	            double angle=(-2*pi*a*j)/l;
	            complex_d W=polar(1.0,angle);
	            sum+=sample*W;
	        }
	        grid3[j][i]+=sum;
	    }
	    
	}
// 		cout<<endl;
// 		for(int i=0;i<l;i++){
// 	    for(int j=0;j<m;j++){
// 	        cout<<grid3[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
	vector<complex_d> X_k(n);
	int z=0;
	for(int i=0;i<m;i++){
	    for(int j=0;j<l;j++){
	        X_k[z]=grid3[j][i];
	        z++;
	    }
	}
	
	for(auto i:X_k) cout<<i<<" ";
}
