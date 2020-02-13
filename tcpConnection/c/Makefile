SERVER = server
CLIENT = client
TEST = Test

.SILENT: all $(SERVER) $(CLIENT) $(TEST) clean
.PHONY: all clean

all: $(SERVER) $(CLIENT) $(TEST)

$(SERVER): $(SERVER).cpp
	g++ -Wall -pedantic $(SERVER).cpp -lws2_32 -o $(SERVER)

$(TEST): $(TEST).cpp
	g++ -Wall -pedantic $(TEST).cpp -lws2_32 -o $(TEST)


$(CLIENT): $(CLIENT).cpp
	g++ -Wall -pedantic $(CLIENT).cpp -lws2_32 -o $(CLIENT)


clean: 
	-rm -f $(SERVER)
	-rm -f $(CLIENT)
