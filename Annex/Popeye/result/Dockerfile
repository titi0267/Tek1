FROM node:12-alpine
WORKDIR /app
COPY . /app
EXPOSE 80
RUN npm install
CMD ["npm", "start", "server.js"]