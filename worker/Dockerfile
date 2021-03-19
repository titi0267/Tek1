FROM maven:3.5-jdk-8-alpine
WORKDIR /app
COPY . /app
RUN mvn dependency:resolve
RUN mvn package

FROM openjdk:8-jre-alpine
EXPOSE 80
CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]