#350. Intersection of Two Arrays II
#When I first look this algorithm, I think it is simple. However, it will take you some time to think about the implementation.
#The first concept into my mind is map.The unordered_map is similar to map in c++, it will not sort according to comparison of its values
#Here is the first implementation
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;//define the map to help charge.
        vector<int>res;
        for(auto a : nums1) ++m[a];
        for(auto a : nums2) {
            if(m[a]-->0) res.push_back(a);
        }
        return res;
    }
#After this, I search some data on the Internet. The first step is to sort on the two vectors.
#And, make comparision with first elements in these two vectors.
#if each of them is equal, and push this element into vector. Both of them push forward.
#if first one is bigger than second one, the second one push forward.
#else the first one push forward.
#Here is the codes:
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i; ++j;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }
        return res;
    }
