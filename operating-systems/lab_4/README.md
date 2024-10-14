
# Task Condition
Write programs for the console process Administrator and the console processes Reader and Writer. To simulate message transmission, introduce special events that denote messages "A", "B", "C", "D" and the end of the session for the Reader and Writer processes. For messages "C" and "D", use events with manual reset.

Only two active Writer processes (using a mutex) and two active Reader processes (using a semaphore) can simultaneously send and receive messages; the transmission of other messages from other processes should be temporarily blocked (in a waiting state).

Administrator Process:
1. Initialize synchronization objects.
2. Request the number of Writer (Reader) processes from the user.
3. Request the number of messages sent for the Writer processes and the number of messages received for the Reader processes (the total number of sent and received messages must match).
4. Start the specified number of Reader and Writer processes.
5. Receive messages from each Writer process and output them to the console, then send them to the Reader processes.
6. Receive a session completion message from each Reader and Writer process and output it to the console in one line.
7. Terminate its work.
Writer Process:
1. Synchronize the work of Writer processes using mutexes.
2. Implement message transmission using events.
3. Request messages consisting of "A" or "B" from the console and send them (one at a time) to the Administrator process.
4. Send a session completion message to the Administrator process.
5. Terminate its work.
Reader Process:
1. Synchronize the work of Reader processes using a semaphore.
2. Implement message transmission using events.
3. Receive messages "C" and "D" from the Administrator process.
4. Output the messages to the console.
5. Send a session completion message to the Administrator process.
6. Terminate its work.
