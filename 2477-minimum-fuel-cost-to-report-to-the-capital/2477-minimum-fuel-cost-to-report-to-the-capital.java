class Solution {
    
    private HashMap<Integer,ArrayList<Integer>> adjList;
    private int seats;
    private int[] visited;
    private long fuel;
    private void constructGraph(int[][]roads){
        for(int[] road : roads){
            adjList.computeIfAbsent(road[0],k->new ArrayList<>()).add(road[1]);
            adjList.computeIfAbsent(road[1],k->new ArrayList<>()).add(road[0]);
        }
    }

    private int[] doDFS(int u){
        if(visited[u] == 1){
            return new int[2];
        }
        visited[u] = 1;
        int[] ans = new int[2];
        int peoples = 1;
        for(int i=0;i<(adjList.get(u)).size();i++){
            int v= adjList.get(u).get(i);
            int[] carsAndPeoples =  doDFS(v);
            fuel = fuel+carsAndPeoples[0];
            peoples = peoples + carsAndPeoples[1];
        };
        ans[0] =  peoples/seats;
        if((peoples) % seats != 0){
            ans[0]++;
        }
        ans[1] = peoples;
        // System.out.println(u+" "+ans[0]+ " "+ans[1]+" "+fuel);
        return ans;
    }
    private void print(){
        for(Map.Entry<Integer,ArrayList<Integer>> entry : adjList.entrySet()){
            System.out.println(entry.getKey()+ " : "+entry.getValue());
        }
    }
    public long minimumFuelCost(int[][] roads, int seats) {
        if(roads.length == 0){
            return 0;
        }
        this.adjList = new HashMap<>();
        this.seats = seats;
        visited = new int[roads.length+1];
        constructGraph(roads);
        // print();
        doDFS(0);
        return fuel;
    }
}