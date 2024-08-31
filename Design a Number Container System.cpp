class NumberContainers {
public:
    NumberContainers() {
        m_pUm = new unordered_map<int,int>();
        m_pUmset = new unordered_map<int,set<int>>();
    }
    
    void change(int index, int number) {
        if(m_pUm->find(index) != m_pUm->end())
            (*m_pUmset)[(*m_pUm)[index]].erase(index);

        (*m_pUm)[index] = number;
        (*m_pUmset)[number].insert(index);
    }
    
    int find(int number) {
        
        if(m_pUmset->find(number) == m_pUmset->end())
            return -1;
        
        if((*m_pUmset)[number].size() == 0)
            return -1;
        
        return *(*m_pUmset)[number].begin();
    }

    unordered_map<int,int> *m_pUm;
    unordered_map<int,set<int>> *m_pUmset;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */