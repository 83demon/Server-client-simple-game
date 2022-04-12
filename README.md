# Server-client-simple-game
Network game, in which you are trying to reach opponent's ball.<br/> In this game, the first player, called a server, listens over the network for the request of joining from the second player, called a client. After the connection is established, two players exchanges 'online' game data, and one of them tries to reach another player's ball.<br />
SFML library required.<br />
Server and client should be considered as two independent projects.<br />
You should put common/ folder in to both projects and specify PORT and public IP in params.txt separated by space.<br />
How to use: run Server project, then run Client project. Wait till connect is successful.<br />
How to play: you can move ball with arrows.<br />
Projects are put in different branches.
