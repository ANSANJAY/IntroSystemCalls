Why can't the application directly access hardware, why do we need system calls?
---------------------------------------------------------------------------------

Advantage of having system calls:

	1. Makes programming easier by freeing users from studying low-level programming characteristics of hardware devices

	2. It greatly increases system security, because kernel can check the accuracy of the request at the interface level before attempting to satisfy it.
