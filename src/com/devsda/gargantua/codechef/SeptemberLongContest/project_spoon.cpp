#include<stdio.h>

unsigned long long int workingArray[] = {0ll ,0ll ,2ll ,3ll ,6ll ,10ll ,20ll ,35ll ,70ll ,126ll ,252ll ,462ll ,924ll ,
                                        1716ll ,3432ll ,6435ll ,12870ll ,24310ll ,48620ll ,
                                        92378ll ,184756ll ,352716ll ,705432ll ,1352078ll ,
                                        2704156ll ,5200300ll ,10400600ll ,20058300ll ,40116600ll ,
                                        77558760ll ,155117520ll ,300540195ll ,601080390ll ,
                                        1166803110ll ,2333606220ll ,4537567650ll ,9075135300ll ,
                                        17672631900ll ,35345263800ll ,68923264410ll ,137846528820ll ,
                                        269128937220ll ,538257874440ll ,1052049481860ll ,2104098963720ll ,
                                        4116715363800ll ,8233430727600ll ,16123801841550ll ,
                                        32247603683100ll ,63205303218876ll ,126410606437752ll ,
                                        247959266474052ll ,495918532948104ll ,973469712824056ll ,
                                        1946939425648112ll ,3824345300380220ll ,7648690600760440ll ,
                                        15033633249770520ll ,30067266499541040ll ,59132290782430712ll ,
                                        118264581564861424ll ,232714176627630544ll ,465428353255261088ll ,
                                        916312070471295267ll};

int findCeil(unsigned long long int N, int start, int end) {
   if(workingArray[end] < N) return end+1;
   if(workingArray[start] == N) return start;
   if(workingArray[end] == N) return end;

   int mid = start + (end - start)/2;

   if( ( (mid == start) || (workingArray[mid-1] < N) ) && (workingArray[mid] >= N) ) return mid;
   if( workingArray[mid] < N && ( (mid == end) || (workingArray[mid + 1] >= N) ) ) return mid+1;

   if( workingArray[mid] > N ) return findCeil(N, start, mid);
   else return findCeil(N, mid+1, end);
}

/*unsigned long long int choose(int n, int k) {
    unsigned long long int r = 1;
    for(int i = 1; i <= k; i++) {
        r *= n--;
        r /= i;
    }
    return r;
}*/

main() {
    //ofstream myfile;
    //myfile.open("output.txt");
    /*for(int i = 2; i <= 62; i++) {
        workingArray[i] = choose( i, i/2 );
    }
    workingArray[63] = 916312070471295267ll;
    */
    /*for(int i = 0; i <= 63; i++) {
        myfile << workingArray[i];
        myfile << " ,";
        //cout << workingArray[i] << endl;
    }
    myfile.close();*/

    int T;
    unsigned long long int N;

    //cin >> T;
    scanf("%d", &T);
    while(T--) {
        //cin >> N;
        scanf("%lld", &N);
        printf("%d\n", findCeil(N, 2, 63));
        //cout << findCeil(N, 2, 63) << endl;
    }

    return 0;
}
