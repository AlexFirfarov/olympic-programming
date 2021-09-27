 
	#include <iostream>
    #include <vector>
     
    int main() {
    	size_t t;
    	std::cin >> t;
    	for (size_t i = 0; i < t; ++i) {
    		long long a, b;
    		std::cin >> a >> b;
    		int rem = 1;
    		std::vector<int> v1;
    		while (a) {
    			if (a % rem) {
    				v1.push_back(a % rem);
    				a -= a % rem;
    			}
    			rem *= 10;
    		}
    		rem = 1;
    		std::vector<int> v2;
    		while (b) {
    			if (b % rem) {
    				v2.push_back(b % rem);
    				b -= b % rem;
    			}
    			rem *= 10;
    		}
    		for(int j = 0; j < v1.size(); ++j){
    			for (int k = 0; k < v2.size();++k) {
    				std::cout << v1[j] << " x " << v2[k];
    				if ((j != v1.size() - 1)|| (k != v2.size() - 1))
    					std::cout << " + ";
    			}
    		}
    		std::cout << std::endl;
    	}
    	return 0;
    }