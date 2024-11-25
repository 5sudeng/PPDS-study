import heapq

class Solution:
    def carPooling(self, trips, capacity):
        onoff = []
        
        for trip in trips:
            heapq.heappush(onoff, (trip[1], trip[0]))
            heapq.heappush(onoff, (trip[2], -trip[0]))

        passengers = 0
        while onoff:
            passengers += heapq.heappop(onoff)[1]
            if passengers > capacity:
                return False 

        return True 