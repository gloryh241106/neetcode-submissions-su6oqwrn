class TimeValue {
    private int timestamp;
    private String value;

    TimeValue(int timestamp, String value) {
        this.timestamp = timestamp;
        this.value = value;
    }

    public int getTimestamp() {
        return this.timestamp;
    }

    public String getValue() {
        return this.value;
    }
}

class TimeMap {
    private HashMap<String, ArrayList<TimeValue>> hashMap;

    public TimeMap() {
        this.hashMap = new HashMap<String, ArrayList<TimeValue>>();
    }
    
    public void set(String key, String value, int timestamp) {
        if (!hashMap.containsKey(key))
            hashMap.put(key, new ArrayList<TimeValue>());

        hashMap.get(key).add(new TimeValue(timestamp, value));
    }
    
    public String get(String key, int timestamp) {
        if (!hashMap.containsKey(key))
            return "";

        ArrayList<TimeValue> temp = hashMap.get(key);
        int left = 0, right = temp.size() - 1;
        String res = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midTimestamp = temp.get(mid).getTimestamp();

            if (midTimestamp <= timestamp) {
                res = temp.get(mid).getValue();
                left = mid + 1;
            }
            else    
                right = mid - 1;
        }

        return res;
    }
}
