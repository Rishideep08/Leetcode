
class VideoSharingPlatform {
private:
    class VideoDetails{
        public:
            int likes;
            int dislikes;
            int views;
            string video;
            VideoDetails(string video){
                this->likes = 0;
                this->dislikes=0;
                this->views=0;
                this->video=video;
            }
    };
    priority_queue<int,vector<int>,greater<int>>pq;
    int maxVideoId = 0;
    unordered_map<int,VideoDetails*> um;
public:
    VideoSharingPlatform() {
        // pq.push(maxVideoId);
    }
    
    int upload(string video) {
        int videoId=maxVideoId;
        if(!pq.empty()){
            videoId = pq.top();  
            pq.pop();
        }else{
            maxVideoId++;
        }
        cout<<videoId<<endl;
        VideoDetails* videoDetails = new VideoDetails(video);
        um[videoId] = videoDetails;
        return videoId;
    }
    
    void remove(int videoId) {
        if(um.find(videoId) != um.end()){
            cout<<videoId<<endl;
            delete um[videoId];
            um.erase(videoId);
            pq.push(videoId);
        }
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        if(um.find(videoId) == um.end()){
            return "-1";
        }
        um[videoId]->views++;
        string &video = um[videoId]->video;
        int length = endMinute;
        if(endMinute>video.size()-1){
            length = video.size()-1;
        }
        // int length = min(endMinute,video.size()-1);
        length = length-startMinute+1;
        return video.substr(startMinute,length);
    }
    
    void like(int videoId) {
        if(um.find(videoId) == um.end()){
            return;
        }
        um[videoId]->likes++;
    }
    
    void dislike(int videoId) {
        if(um.find(videoId) == um.end()){
            return;
        }
        um[videoId]->dislikes++;
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        if(um.find(videoId) == um.end()){
            return vector<int>(1,-1);
        }
        vector<int> result(2,0);
        result[0] = um[videoId]->likes;
        result[1] = um[videoId]->dislikes;
        return result;
    }
    
    int getViews(int videoId) {
        if(um.find(videoId) == um.end()){
            return -1;
        }
        return um[videoId]->views;
    }
};

/**
 * Your VideoSharingPlatform object will be instantiated and called as such:
 * VideoSharingPlatform* obj = new VideoSharingPlatform();
 * int param_1 = obj->upload(video);
 * obj->remove(videoId);
 * string param_3 = obj->watch(videoId,startMinute,endMinute);
 * obj->like(videoId);
 * obj->dislike(videoId);
 * vector<int> param_6 = obj->getLikesAndDislikes(videoId);
 * int param_7 = obj->getViews(videoId);
 */