#INICIAR CONTENEDOR
docker start capos

#COMPILAR
docker exec capos make -C /root

#EJECUTAR
# sudo chown -R $USER
./run.sh gdb

#CERRAR CONTENEDOR
docker stop capos