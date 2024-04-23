FROM gcc:latest
WORKDIR C:\Users\nagyg\Documents\proiect_sincretic_sah
COPY main.c .
RUN gcc -o main main.c
CMD ["./main"]