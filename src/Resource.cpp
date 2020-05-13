#include"Resource.h"

 Resource::Resource(Server* server, Json::Value value):
	JSON(value),server(server){
    #ifdef DEBUG
	std::cout <<"Constructor is working..."<<std::endl;
    #endif 
  }

 Json::Value Resource::get_attribute(const std::string attribute_name){ //getting attribute value
	return JSON["attributes"][attribute_name];
  };

 Json::Value Resource::get_id(){ //getting id value
	return JSON["id"];
  };

 Json::Value Resource::get_type(){ //getting type value
	return JSON["type"];
  };

 void Resource::set_attribute(const std::string name, bool value){
	JSON["attributes"][name]=value;
	
  };

 void Resource::set_attribute(const std::string name,const std::string value){ //setting attribute name and value
	JSON["attributes"][name]=value;

  };

 void Resource::set_attribute(const std::string name, int value){
	JSON["attributes"][name]=value;

  };

 void Resource::set_attribute(const std::string name, double value){

	JSON["attributes"][name]=value;
  };

 void Resource::set_id(const std::string value){
	JSON["id"]=value;
  };

 void Resource::set_type(const std::string value){
	JSON["type"]=value;
  };

 Json::Value Resource::get_data(){
	return JSON; //returns JSON["data"]
  };

 std::string Resource::get_server(){
	std::string* a = (std::string*)server;
	std::string b = *a;
	return b;
  };

 void Resource::set_server(const std::string server_new){
	Server server(server_new);
  };

 void Resource::store(){  //sending data POST
  CURL *curl;
  CURLcode res;

  res = curl_global_init(CURL_GLOBAL_DEFAULT);
  /* Check for errors */ 
  if(res != CURLE_OK) {
    fprintf(stderr, "curl_global_init() failed: %s\n",
            curl_easy_strerror(res));
 }
 else{
  curl = curl_easy_init();
    
   if(curl) {
	/* First set the URL that is about to receive our POST. */ 
	curl_easy_setopt(curl, CURLOPT_URL, "http://jsonapiplayground.reyesoft.com/v2/authors/1");  // Server server http part is symbolized
	/*we add headers for Accept, Content-Type, Authorization */
	  curl_slist* h = NULL;
	  h = curl_slist_append(h, "Authorization: Someone Someone");
	  h = curl_slist_append(h, "Accept: application/vnd.api+json");
	  h = curl_slist_append(h, "Content-Type: application/vnd.api+json");
	  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, h);
      
	 /* Now specify we want to POST data */ 
	  curl_easy_setopt(curl, CURLOPT_POST, 1L);
 
	 /* Now specify what we want to send */ 
	  curl_easy_setopt(curl, CURLOPT_POSTFIELDS,JSON);
 
	 /* verbose debug output */ 
	  curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
 
         /* Perform the request, res will get the return code */ 
	  res = curl_easy_perform(curl);

	  curl_easy_cleanup(curl);
	  curl_global_cleanup();
    }}
}
 Resource::~Resource(){
    #ifdef DEBUG
	std::cout<<"Destructor is working..."<<std::endl;
    #endif
  }
