
#include "Camera.hpp"

camera::camera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch):
Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), Zoom(ZOOM){
	this->Position = position;
	this->WorldUp = up;
	this->Yaw = yaw;
	this->Pitch = pitch;
	updateCameraVectors();
}

camera::camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch):
Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), Zoom(ZOOM){
	this->Position = glm::vec3(posX, posY, posZ);
	this->WorldUp = glm::vec3(upX, upY, upZ);
	this->Yaw = yaw;
	this->Pitch = pitch;
	updateCameraVectors();
}

glm::mat4 camera::GetViewMatrix(){
	return glm::lookAt(this->Position, this->Position + this->Front, this->Up);
}

void camera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime){
	GLfloat velocity = this->MovementSpeed * deltaTime;
	if(direction == FORWARD)
		Position += Front * velocity;
	if(direction == BACKWARD)
		Position -= Front * velocity;
	if(direction == RIGHT)
		Position += Right * velocity;
	if(direction == LEFT)
		Position -= Right * velocity;
}

void camera::ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch){
	xoffset *= MouseSensitivity;
	yoffset *= MouseSensitivity;
	
	Yaw += xoffset;
	Pitch += yoffset;
	
	if(constrainPitch){
		if(Pitch >= 89.0f)
			Pitch = 89.0f;
		if(Pitch <= -89.0f)
			Pitch = -89.0f;
	}
	updateCameraVectors();
}

void camera::ProcessMouseScroll(GLfloat yoffset){
	if(Zoom >= 1.0f && Zoom <= 45.0f)
		Zoom -= yoffset;
	if(Zoom <= 1.0f)
		Zoom = 1.0f;
	if(Zoom >= 45.0f)
		Zoom = 45.0f;
}

void camera::updateCameraVectors(){
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw) * cos(glm::radians(Pitch)));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);
	
	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));
}

