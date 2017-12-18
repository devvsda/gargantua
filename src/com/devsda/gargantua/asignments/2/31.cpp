#include<iostream>

struct frame {
    int pageNumber;
    struct frame *next;
    struct frame *prev;
};

struct LRU {
    int totalFrames;
    int currentPages;
    struct frame *mostRecently;
    struct frame *leastRecently;
};

struct LRU *createLRU(int pages) {
    struct LRU *node = (struct LRU *)malloc(sizeof(struct LRU));
    node->totalFrames = pages;
    node->currentPages = 0;
    node->mostRecently = NULL;
    node->leastRecently = NULL;
    return node;
}
struct frame* presentPages[1000];

void pushPage(struct LRU *lru, int pageNumber) {
    if(lru->currentPages < lru->totalFrames) {
        if( presentPages[pageNumber] == NULL) {
            struct frame *newNode = (struct frame*)malloc(sizeof(struct frame));
            newNode->pageNumber = pageNumber;
            newNode->next = lru->mostRecently;
            if(lru->mostRecently != NULL) lru->mostRecently->prev = newNode;
            lru->mostRecently = newNode;
            presentPages[pageNumber] = newNode;
        }
        else {
            struct frame *thisNode = presentPages[pageNumber];
            if(thisNode->prev) thisNode->prev->next = thisNode->next;
            if(thisNode->next) thisNode->next->prev = thisNode->prev;
            thisNode->next = lru->mostRecently;
            thisNode->prev = NULL;
            if(lru->mostRecently != NULL) lru->mostRecently->prev = thisNode;
            lru->mostRecently = thisNode;
        }
        lru->currentPages++;
    }
    else {
        if(presentPages[pageNumber] == NULL) {
            struct frame *newNode = (struct frame*)malloc(sizeof(struct frame));
            newNode->pageNumber = pageNumber;
            newNode->prev = NULL;
            newNode->next = lru->mostRecently;
            lru->mostRecently->prev = newNode;
            lru->mostRecently = newNode;
            presentPages[pageNumber] = newNode;
            lru->leastRecently = lru->leastRecently->prev;
            lru->leastRecently->next = NULL;
            delete(presentPages[pageNumber]);
            presentPages[pageNumber] = NULL;
        }
        else {
            struct frame *thisNode = presentPages[pageNumber];
            if(thisNode->prev) thisNode->prev->next = thisNode->next;
            if(thisNode->next) thisNode->next->prev = thisNode->prev;
            thisNode->next = lru->mostRecently;
            thisNode->prev = NULL;
            if(lru->mostRecently != NULL) lru->mostRecently->prev = thisNode;
            lru->mostRecently = thisNode;
        }
    }

}

main() {
    struct LRU *lru = createLRU(4);
    return 0;
}

