class MyCalendarTwo:
    def __init__(self):
        self.calendar = []
        self.overlaps = []

    def book(self, startTime: int, endTime: int) -> bool:
        # Step 1: Check if new booking would cause a triple booking
        for overlap_start, overlap_end in self.overlaps:
            if max(startTime, overlap_start) < min(endTime, overlap_end):
                return False
        
        # Step 2: Add new overlaps caused by this booking
        for event_start, event_end in self.calendar:
            overlap_start = max(startTime, event_start)
            overlap_end = min(endTime, event_end)
            if overlap_start < overlap_end:  # Valid overlap
                self.overlaps.append((overlap_start, overlap_end))
        
        # Step 3: Add the booking to the calendar and return True
        self.calendar.append((startTime, endTime))
        return True

    def overlap(self, A: list, B: list) -> list:
        # A와 B가 겹치는 경우 정확한 겹치는 시간 범위를 계산합니다.
        if max(A[0], B[0]) < min(A[1], B[1]):
            return [max(A[0], B[0]), min(A[1], B[1])]
        return [-1, -1]
