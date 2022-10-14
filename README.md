<h1>Secure Biba Reference Monitor</h1>

<p> 
Requires any C/C++ to compile for your system. I personally used the GNU C Compiler. It can be downloaded from <a href="https://gcc.gnu.org/">here<a>
</p>

<p>
This program uses the Biba security model to implement a secure banking system, with queries acting as reads and deposits/withdrawals acting as writes. It takes input from a file (I have provided one as an example) and passes the commands to the reference monitor, if it is a valid command. Depending on the command, the reference monitor with either grant or deny access to the file. Any commands that are denied accesses or are considered bad instructions will be printed out. Otherwise, a message denoting the successful action will be printed
</p>
