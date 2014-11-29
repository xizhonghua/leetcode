class LRUCache{

struct Node {
    int key;
    int val;
    int time;
    int index;
    
    Node() { index = -1; }
    Node(int key, int val, int time) {
        this->key = key;
        this->val = val;
        this->time = time;
        this->index = -1;
    }
};
    
public:
    LRUCache(int capacity) {
        this->m_clock = 0;
        this->m_map.clear();
        this->m_capacity = capacity;
        this->m_size = 0;
        this->m_heap = vector<Node*>(2*capacity+2);
    }
    
    ~LRUCache() {
        for(auto n : m_heap) delete n;
        m_heap.clear();
        m_map.clear();
    }
    
    int get(int key) {
        this->m_clock++;
        
        auto node = this->m_map[key];
        if(!node) return -1;
        
        this->updateUsedTime(node);
        return node->val;
    }
    
    void set(int key, int value) {
        this->m_clock++;
        
        auto node = this->m_map[key];
        
        if(node == NULL) {
            // cache is full
            if(m_size == m_capacity) {
                // remove the node with smallest used time
                auto min_node = this->extractMinNode();
                delete min_node;
            } else {
                m_size++;
            }
            
            // create a new node
            auto new_node = new Node(key, value, m_clock);
            this->insert(new_node);
        } else {
            node->val = value;
            this->updateUsedTime(node);
        }
    }
private:
    // insert a node into heap, always at the end of the heap
    void insert(Node* node) {
        node->index = m_size;
        this->m_map[node->key] = node;
        this->m_heap[node->index] = node;
    }
    
    // extract the min node from heap
    Node* extractMinNode() {
        auto node = m_heap[1];
        m_heap[1] = m_heap[m_size];
        m_heap[1]->index = 1;
        
        m_heap[m_size] = NULL;
        m_map[node->key] = NULL;
        
        this->heapify(1);
        
        return node;
    }
    
    // update used time for a node
    void updateUsedTime(Node* node) {
        node->time = m_clock;
        heapify(node->index);
    }
    
    void heapify(int i) {
        auto p = m_heap[i];
        auto l = m_heap[i*2];
        auto r = m_heap[i*2+1];
        
        if(!l && !r) return;
        
        if(l && r && p->time < l->time && p->time < r->time) return;
        
        auto m = ((l && r) ? (l->time < r->time ? l : r) : (l?l:r));
        
        if(p->time > m->time) {
            swap(m_heap[p->index], m_heap[m->index]);
            swap(p->index, m->index);
            heapify(p->index);
        }
    }
    
    int m_capacity;
    int m_size;
    int m_clock;
    unordered_map<int, Node* > m_map;
    vector<Node*> m_heap;
};
