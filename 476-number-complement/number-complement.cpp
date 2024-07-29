class Solution {
public:
    int findComplement(int num) {
        bitset<32> bits(num);
        int highestBit = 0;
        
        // Find the highest bit set
        for (int i = 31; i >= 0; i--){
            if (bits.test(i)){
                highestBit = i;
                break;
            }
        }
        
        // Create a mask of all 1s up to the highest bit
        bitset<32> mask;
        for (int i = 0; i <= highestBit; i++){
            mask.set(i);
        }

        // Calculate the complement
        bitset<32> complement = bits ^ mask;
        return complement.to_ulong();
    }
};