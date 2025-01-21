#include <iostream>
#include <string>

using namespace std;

int main() {

	string row;
	char container, black = 'B';
	
	short t, i, j, q;
	int n, k, counter, peak, ans;
	
	cin >> t;
	for (i = 0; i < t; i++) { 
		cin >> n >> k >> row;
		short pars[n] = {0};
		
		peak = 0; 
		if (k < n) {
			counter = 0;
			
			for (j = 0; j < n; j++) {
				container = row.at(j);
				
				if (container == black)
					pars[j] = 1;
			}
			
			for (j = 0; j < k; j++) 
				peak += pars[j];

			counter = peak;
			
			for(j = 0, q = k; q < n; j++, q++) {
	            counter -= pars[j] - pars[q];
	        	if(counter > peak)
	                peak = counter;
			}
			
			ans = k - peak;
		} else {
			for (j = 0; j < n; j++) {
				container = row.at(j);
				
				if (container == black)
					peak++;
			}
			
			ans = k - peak;
			
		}
		
		cout << ans << "\n";	
	}
	
	return 0;
}