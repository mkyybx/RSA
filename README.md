# RSA
A simple C-based RSA decryptor.

I feel very sorrowful to find that I lost the source code for encryption and key generator programs, but fortunately I find their binarys and make an release.

The program is compiled with Visual Studio 2013, which means its runtime is needed to run the binaries.

The input and output meanings:
Please do not include anotations in the input file.

Encrypting:
input.txt:

4337      #p
7283      #q
31586371  #p*q
16655     #e
#the following is the content to be encrypted
What is friendship? Friendship is a bridge constructed by you and me

The program will use input.txt and key.txt to produce the encrypted file output.txt.

Decrypting:
