/*
name - Akshada kanhaiyalal khairnar
Sy-b   roll no.38
Assignment 6
*/

// Include necessary header files
#include <stdio.h>
#include<conio.h>

// Define constants for the maximum number of frames and pages.
#define MAX_FRAMES 3 // Maximum number of frames in memory
#define MAX_PAGES 10 // Maximum number of pages

// Function to find the index of the farthest page in the future (used in Optimal algorithm)
int findOptimal(int pages[], int n, int index, int frame[])
{
    int res = -1, farthest = index;
    // Loop through all frames to determine the farthest page in the future
    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        // Check each frame to see when it will be accessed in the future
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                // If the page is found in the future, update the farthest index
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        // If the page is not found in the future, return this frame index
        if (j == n)
            return i;
    }
    return (res == -1) ? 0 : res; // If no frame is farthest, return the first frame index
}

// Function to simulate FIFO page replacement algorithm
void fifo(int pages[], int n)
{
    int frame[MAX_FRAMES], front = 0, rear = 0, pageFaults = 0;
    bool pageFound = false;

    printf("\nUsing FIFO Algorithm:\n");

    // Initialize all frames to -1 (empty)
    for (int i = 0; i < MAX_FRAMES; i++)
        frame[i] = -1;

    // Process each page in the page reference sequence
    for (int i = 0; i < n; i++) {
        pageFound = false;

        // Check if the current page is already in one of the frames
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frame[j] == pages[i]) {
                pageFound = true; // Page is already in memory, no page fault
                break;
            }
        }

        // If page is not found (page fault occurs)
        if (!pageFound) {
            frame[rear] = pages[i]; // Load the new page into memory (rear position)
            rear = (rear + 1) % MAX_FRAMES; // Circular increment for the rear position
            pageFaults++; // Increment page fault count
        }

        // Print the current state of the frames after loading the page
        printf("Page %d -> ", pages[i]);
        for (int j = 0; j < MAX_FRAMES; j++)
            printf("%d ", frame[j]); // Display the current pages in memory
        printf("\n");
    }

    // Output the total number of page faults that occurred
    printf("Total Page Faults: %d\n", pageFaults);
}

// Function to simulate LRU (Least Recently Used) page replacement algorithm
void lru(int pages[], int n)
{
    int frame[MAX_FRAMES], pageFaults = 0, recent[MAX_FRAMES];
    bool pageFound = false;

    printf("\nUsing LRU Algorithm:\n");

    // Initialize frames and recent array
    for (int i = 0; i < MAX_FRAMES; i++) {
        frame[i] = -1;  // Initialize all frames to empty
        recent[i] = 0;  // Initialize recent counter (used to track last used time)
    }

    // Process each page in the page reference sequence
    for (int i = 0; i < n; i++) {
        pageFound = false;

        // Check if the current page is already in one of the frames
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frame[j] == pages[i]) {
                recent[j] = i + 1; // Update the recent counter for this page
                pageFound = true; // Page is found in memory, no page fault
                break;
            }
        }

        // If page is not found (page fault occurs)
        if (!pageFound) {
            int leastRecent = 0;
            // Find the least recently used page by comparing the recent counters
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (recent[j] < recent[leastRecent])
                    leastRecent = j; // Update the least recently used index
            }
            // Replace the least recently used page with the new page
            frame[leastRecent] = pages[i];
            recent[leastRecent] = i + 1; // Update the recent counter
            pageFaults++; // Increment page fault count
        }

        // Print the current state of the frames after loading the page
        printf("Page %d -> ", pages[i]);
        for (int j = 0; j < MAX_FRAMES; j++)
            printf("%d ", frame[j]); // Display the current pages in memory
        printf("\n");
    }

    // Output the total number of page faults that occurred
    printf("Total Page Faults: %d\n", pageFaults);
}

// Function to simulate Optimal page replacement algorithm
void optimal(int pages[], int n)
{
    int frame[MAX_FRAMES], pageFaults = 0;
    bool pageFound = false;

    printf("\nUsing Optimal Algorithm:\n");

    // Initialize all frames to -1 (empty)
    for (int i = 0; i < MAX_FRAMES; i++)
        frame[i] = -1;

    // Process each page in the page reference sequence
    for (int i = 0; i < n; i++) {
        pageFound = false;

        // Check if the current page is already in one of the frames
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frame[j] == pages[i]) {
                pageFound = true; // Page is already in memory, no page fault
                break;
            }
        }

        // If page is not found (page fault occurs)
        if (!pageFound) {
            // Find the optimal page to replace by calling findOptimal() function
            int index = findOptimal(pages, n, i + 1, frame);
            frame[index] = pages[i]; // Replace the selected page with the new page
            pageFaults++; // Increment page fault count
        }

        // Print the current state of the frames after loading the page
        printf("Page %d -> ", pages[i]);
        for (int j = 0; j < MAX_FRAMES; j++)
            printf("%d ", frame[j]); // Display the current pages in memory
        printf("\n");
    }

    // Output the total number of page faults that occurred
    printf("Total Page Faults: %d\n", pageFaults);
}

int main()
{
    int pages[MAX_PAGES], n;

    // Ask user for the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    // Ask user to enter the page reference sequence
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    // Simulate FIFO, LRU, and Optimal page replacement algorithms
    fifo(pages, n);
    lru(pages, n);
    optimal(pages, n);

    return 0;
}
