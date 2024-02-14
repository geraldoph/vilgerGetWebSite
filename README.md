# vilgerGetWebSite

The "Website Downloader" is a simple C++ application that facilitates the downloading of website content for offline browsing. Users can input a start page URL and choose the desired download level to retrieve HTML, images, CSS, and other assets. The application constructs a corresponding wget command, displays it for user reference, and executes the command using the system function.

# Key Features:

User-friendly interface for providing the start page URL and download level.
Automatic generation and display of wget command for transparency and user reference.
Efficient use of libcurl for executing the wget command directly from the C++ program.
Customizable download levels to control the depth of the download.

# How to Use:

In Linux Terminal run vilgerGetWebSite.
Enter the start page URL when prompted.
Optionally, specify the desired download level (default is 2).
The program generates and displays the wget command.
The command is executed, and the website content is downloaded to the specified directory.
Note: Ensure compliance with the website's terms of service regarding automated downloading and scraping.

Feel free to customize and expand this description based on additional features or functionalities you may add to the application.
