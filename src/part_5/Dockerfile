FROM nginx
# USER root

HEALTHCHECK --interval=5m --timeout=3s \
    CMD curl -f http://localhost/ || exit 1

COPY ./hello.c /my_server/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./run_hello.sh /my_server/

WORKDIR /my_server/

RUN apt-get install \
    && apt update \
    && apt install gcc -y \
    && apt install spawn-fcgi -y \
    && apt install libfcgi-dev -y \
    && rm -rf /var/lib/apt/lists \
    && gcc hello.c -o hello -l fcgi \
    && chmod +x run_hello.sh

RUN chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /var/cache/nginx; \
    chown -R nginx:nginx /home; \
    chown -R nginx:nginx /miniweb; \
    touch /var/run/nginx.pid; \
    chown -R nginx:nginx /var/run/nginx.pid; \
    chmod u-s /usr/bin/gpasswd; \
    chmod u-s /usr/bin/newgrp; \
    chmod u-s /bin/su; \
    chmod u-s /bin/mount; \
    chmod u-s /bin/umount; \
    chmod u-s /usr/bin/chsh; \
    chmod u-s /usr/bin/chfn; \
    chmod u-s /usr/bin/chsh; \
    chmod 255 /usr/bin/expiry; \
    chmod 255 /usr/bin/wall; \
    chmod 255 /sbin/unix_chkpwd; \
    chmod 255 /usr/bin/chage; \
    chmod 755 /usr/bin/passwd;

USER nginx

# CMD ["/my_server/run_hello.sh"]
# CMD ./my_server/run_hello.sh

ENTRYPOINT ["sh", "./run_hello.sh"]