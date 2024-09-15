#include <iostream>
extern "C" {
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
}

class dmpegtestr {
public:
    dmpegtestr(const std::string &filePath) : filePath(filePath) {
        avformat_network_init();
    }

    ~dmpegtestr() {
        avformat_network_deinit();
    }

    void test() {
        AVFormatContext *formatContext = nullptr;

        // 打开视频文件
        if (avformat_open_input(&formatContext, filePath.c_str(), nullptr, nullptr) < 0) {
            std::cerr << "Could not open video file: " << filePath << std::endl;
            return;
        }

        // 打印视频文件信息
        std::cout << "Format: " << formatContext->iformat->long_name << std::endl;

        // 查找视频流并打印帧率
        for (unsigned int i = 0; i < formatContext->nb_streams; ++i) {
            if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
                double frameRate = av_q2d(formatContext->streams[i]->avg_frame_rate);
                std::cout << "Frame rate: " << frameRate << " fps" << std::endl;
                break;
            }
        }

        avformat_close_input(&formatContext);
    }

private:
    std::string filePath;
};

// 示例用法
int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <video_file>" << std::endl;
        return 1;
    }

    dmpegtestr tester(argv[1]);
    tester.test();

    return 0;
}
