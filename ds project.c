#include <stdio.h>
Day* temp = head;
while (temp != NULL) {
if (temp->date == date) {
snprintf(temp->event, sizeof(temp->event), "%s", event);
return;
}
temp = temp->next;
}
printf("Date %d not found in the calendar.\n", date);
}
int main() {
Day* calendar = NULL;
int daysInMonth, startDay;
const char* daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
// Get the number of days in the month from the user
printf("Enter the number of days in the month: ");
scanf("%d", &daysInMonth);
// Get the starting day of the week from the user
printf("Enter the starting day of the week (0 for Sunday, 1 for Monday, ..., 6 for Saturday): ");
scanf("%d", &startDay);
// Create the calendar
for (int i = 1; i <= daysInMonth; i++) {
appendDay(&calendar, i, daysOfWeek[(i - 1 + startDay) % 7]);
}
// Allow the user to add events
int addMoreEvents = 1;
while (addMoreEvents) {
int eventDate;
char eventDescription[100];
printf("Enter the date for the event (1-%d): ", daysInMonth);
scanf("%d", &eventDate);
printf("Enter the event description: ");
getchar(); // Consume newline character left by scanf
fgets(eventDescription, sizeof(eventDescription), stdin);
eventDescription[strcspn(eventDescription, "\n")] = '\0'; // Remove the newline character from
the input
addEvent(calendar, eventDate, eventDescription);
printf("Do you want to add another event? (1 for yes, 0 for no): ");
scanf("%d", &addMoreEvents);
}
// Print the calendar
printCalendar(calendar);
// Free the memory allocated for the calendar
freeCalendar(calendar);
return 0;
}