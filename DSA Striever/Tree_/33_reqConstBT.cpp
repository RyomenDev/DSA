
// ! Requirements needed to construct a Unique Binary Tree | Theory

/*
^ A) Preorder[Root,L,R] & PostOrder[L,R,Root]
%        1 2 3               3 2 1
               1                  1
             /                 /                     // both gives same preOrder and PostOrder
           2                2                      // / unique binary tree not possible
         /                    \
       3                       3
*/
/*
^ B) InOrder[L,Root,R] & PreOrder[Root,L,R]         // /  Possible
*/
/*
^ C) InOrder[L,Root,R] & PostOrder[L,R,Root]         // /  Possible
*/