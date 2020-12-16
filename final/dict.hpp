
template<class K, class V>
V *Dict<K, V>::find(K k) {
    bool flag = false;
    unsigned int num = 0;
    list<K>::iterator itor = keys.begin();
    for (itor = keys.begin(); itor != keys.end(); ++itor){
        if ((*itor) == k){
            flag = true;
            break;
        }
        num++;
    }
    if (flag)
        return &values[num];
    else
        return NULL;
}

template<class K, class V>
void Dict<K, V>::insert(K k, V v) {
    bool flag = false;
    unsigned int num = 0;
    for (list<K>::iterator itor = keys.begin(); itor != keys.end(); ++itor, num++){
        if ((*itor) == k){
            flag = true;
            break;
        }
    }
    if (flag)
        values[num] = v;
    else{
        keys.push_back(k);
        values.push_back(v);
    }
}

template<class K, class V>
void Dict<K, V>::remove(K k) {
    bool flag = false;
    list<K>::iterator itor = keys.begin();
    deque<V>::iterator dit = values.begin();
    for (itor = keys.begin(); itor != keys.end(); ++itor, dit++){
        if ((*itor) == k){
            flag = true;
            break;
        }
    }
    if (flag){
        keys.remove(k);
        values.erase(dit);
    }
}

template<class K, class V>
unsigned int Dict<K, V>::size() {
    unsigned int num = 0;
    list<K>::iterator itor = keys.begin();
    for (itor = keys.begin(); itor != keys.end(); ++itor){
        num++;
    }
    return num;
}