class Solution {
    public int maxProfit(int[] a) {
        int n = a.length;
        int finalSum = 0;
        int currBuy = a[0];
        int tempSell = 0;
        int tempSum = 0;
    
    for (int i = 1; i < n; i++){
        // System.out.println("Current Buy " + currBuy);
        // System.out.println("Current Sell " + tempSell);
        // System.out.println("Final Sum" + finalSum);
        tempSell = a[i];
        if (currBuy > tempSell){
            currBuy = a[i];
            continue;
        }
        tempSum = tempSell - currBuy;
        System.out.println(tempSum);
        // if (tempSum <= 0){
        //     continue;
        // }
        if (tempSum >= finalSum){
            finalSum = tempSum;
        }
        // finalSum = Math.max(finalSum,tempSum)
        }
        
    return finalSum;
    }
}