#include<iostream>

//#include<FosDef.h>
//#include<fossdk.h>

#include<pthread.h>

#define IMAGE_WIDTH 1280
#define IMAGE_HEIGHT 720

#include<boost/filesystem.hpp>

//class FoscamGrabber
//{
//private:

//#define NO_OF_CAMS 1

//    int error_sdk;
//    int timeout;

//    int im_cols;
//    int im_rows;
//    int bytes_per_pixel;


//    std::string URLs[NO_OF_CAMS];
//    std::string UIDs[NO_OF_CAMS];


//    std::string  USERNAME = "admin";
//    std::string PASSWORD = "admin";


//    unsigned short WebPort = 88;
//    unsigned short MediaPort = 888;

//    unsigned int camera_ids[NO_OF_CAMS];
//    int usr_ids[NO_OF_CAMS];

//    unsigned char* data[NO_OF_CAMS];

//    pthread_t  thread_grabber;

//    void* (FoscamGrabber::*cb)(void* args);

//public:

//    bool update;

//    FoscamGrabber()
//    {
//        error_sdk = 0;
//        timeout = 100;

//        im_cols = IMAGE_WIDTH;
//        im_rows = IMAGE_HEIGHT;
//        bytes_per_pixel = 3;

//        update = false;

//        URLs[0] = std::string("192.168.2.108");
//        //        URLs[1] = std::string("192.168.2.101");
//        //        URLs[2] = std::string("192.168.2.101");
//        //        URLs[3] = std::string("192.168.2.101");

//        UIDs[0] =  "JKHXHUMNJ4GYVTG9111A";
//        //        UIDs[1] =  "JKHXHUMNJ4GYVTG9111A";
//        //        UIDs[2] =  "JKHXHUMNJ4GYVTG9111A";
//        //        UIDs[3] =  "JKHXHUMNJ4GYVTG9111A";

//        FosSdk_SetLogLevel(LEVEL_NONE);

//        error_sdk =  FosSdk_Init();
//        if(!error_sdk)
//        {
//            std::cout << "Couldn't Initialize Foscam SDK\n... EXITING\n";
//            return;
//        }

//        std::cout << "Opening Handle To Cameras\n";

//        for(int i=0;i<NO_OF_CAMS;i++)
//        {
//            camera_ids[i] = FosSdk_Create(
//                        (char*)URLs[i].c_str(),(char*) UIDs[i].c_str(),
//                        (char*)USERNAME.c_str(), (char*)PASSWORD.c_str(),
//                        WebPort, MediaPort,
//                        FOSIPC_H264, FOSCNTYPE_P2P);

//             if(!camera_ids[i])
//            {
//                std::cout << "Opening Handle To Camera ID " << i << "Failed...Exiting\n";
//                return;
//            }
//        }

//        for(int i=0;i<NO_OF_CAMS;i++)
//        {
//            error_sdk =FOSCMDRET_FAILD;

//            while (error_sdk != FOSCMDRET_OK)
//                error_sdk = FosSdk_Login(camera_ids[i], &usr_ids[i], timeout);
//        }
//        std::cout << "Logged Into The Cameras Succesfully\n";

//        //        error_sdk = 1;
//        //        for(int i=0;i<NO_OF_CAMS;i++)
//        //            error_sdk = FosSdk_CheckHandle(camera_ids[i], &usr_ids[i]);


//        for(int i=0;i<NO_OF_CAMS;i++)
//            error_sdk = FosSdk_OpenVideo(camera_ids[i], FOSSTREAM_MAIN, timeout);

//        std::cout << "Opened Video Streams Succesfully\n";

//        for(int i=0;i<NO_OF_CAMS;i++)
//            data[i] = (unsigned char*)malloc(im_cols * im_rows * bytes_per_pixel );


//        cb  = &FoscamGrabber::callback_thread_grabber;

//        pthread_create(&thread_grabber,NULL,reinterpret_cast<void* (*)(void*)>(&FoscamGrabber::callback_thread_grabber),this);

//    }


//    ~FoscamGrabber()
//    {
//        std::cout << "Releasing Resources\n";

//        pthread_cancel(thread_grabber);

//        for(int i=0;i<NO_OF_CAMS;i++)
//            error_sdk = FosSdk_CloseVideo(camera_ids[i], timeout);

//        for(int i=0;i<NO_OF_CAMS;i++)
//            free(data[i]);

//        for(int i=0;i<NO_OF_CAMS;i++)
//        {
//            error_sdk =FOSCMDRET_FAILD;
//            while (error_sdk != FOSCMDRET_OK)
//                FosSdk_Logout(camera_ids[i], timeout);
//        }

//        for(int i=0;i<NO_OF_CAMS;i++)
//            FosSdk_Release(camera_ids[i]);

//        FosSdk_DeInit();

//    }

//    void* callback_thread_grabber(void* args)
//    {
//         std::cout << "IN THREAD\n";

//         while(1)

//         {
//             int buffer_length = 0;
//        char* local_data = NULL;

//       for(int i=0;i<NO_OF_CAMS;i++)
//        {

//            error_sdk = FosSdk_GetVideoData(this->camera_ids[i], &local_data, &buffer_length,FOSDECTYPE_BGR24);
//            int offset = buffer_length - IMAGE_WIDTH* bytes_per_pixel * IMAGE_HEIGHT;

//            update = true;

//            if (error_sdk == FOSCMDRET_OK && local_data && update)
//            {
//              std::cout << "OFFSET =  " << offset << " " << buffer_length << " DATA VALID\n";
//              memcpy((void*)this->data[i], (void*)(local_data + offset), (IMAGE_WIDTH* bytes_per_pixel * IMAGE_HEIGHT));
//                update = false;

//            }
//        }
//         }
//    }

//    int getvideo_data(void)
//    {
//        int buffer_length = 0;
//        char* local_data = NULL;

//        for(int i=0;i<NO_OF_CAMS;i++)
//        {

//            error_sdk = FosSdk_GetVideoData(camera_ids[i], &local_data, &buffer_length,FOSDECTYPE_BGR24);
//            int offset = buffer_length - IMAGE_WIDTH* bytes_per_pixel * IMAGE_HEIGHT;

//            update = true;

//            if (error_sdk == FOSCMDRET_OK && update)
//            {
//                memcpy((void*)data[i], (void*)(local_data + offset), (IMAGE_WIDTH* bytes_per_pixel * IMAGE_HEIGHT));
//                update = false;
//                std::cout << "OFFSET =  " << offset << " DATA VALID\n";
//            }
//        }

//    }

//};

int main(int argc, char** argv)
{

    boost::filesystem::create_directories("/home/isl-server/ashishishihasihsishs");

//    FoscamGrabber foscam_grabber;

//    while(1)
    {
    }
    //    while(1)
    //    {
    ////        foscam_grabber.update = true;
    //        foscam_grabber.getvideo_data();

    //    }


    return 0;
}


