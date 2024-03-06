class MedianFinder {
private:
    vector<int> data;
public:
    
    MedianFinder() {
     
    }
    
    void addNum(int num) {
      if(data.size() == 0) data.push_back(num);
      else {
          int x = data.end() - upper_bound(data.begin(),data.end(),num);
          data.insert(data.end() - x, num);
      }
    }
    
    double findMedian() {
       if(data.size() % 2 == 1) {
          return (double) data[data.size()/2];
       }
       
       return (double) (data[data.size()/2 - 1] + data[data.size()/2])/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */