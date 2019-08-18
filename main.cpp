//#include <iostream>
//#include <algorithm>
//
//#include <Eigen/Core>
//#include <Eigen/Dense>
//#include <sophus/so3.h>
//
//using namespace std;
//
//int main()
//{
//    Eigen::Vector3d w(0.01, 0.02, 0.03);
//    Eigen::Matrix3d R = Eigen::Matrix3d::Identity();
//    Eigen::AngleAxisd angle(Eigen::AngleAxisd(0.5,Eigen::Vector3d::UnitX()));
//    R = angle;
//    Sophus::SO3 SO3_w(0.01, 0.02, 0.03);
//    Eigen::Matrix3d R_update = R * SO3_w.matrix();
//
//    Eigen::Quaterniond q(R);
//    Eigen::Quaterniond qw(1, 0.005, 0.01, 0.015);
//    Eigen::Quaterniond q_update = q * qw;
//    q_update.normalize();
//
//    cout << "R: " << R_update.eulerAngles(2,1,0).transpose() << endl;
//    cout << "q: " << q_update.toRotationMatrix().eulerAngles(2,1,0).transpose() << endl;
//    return 0;
//}


#include <vector>
#include <list>

#include <iostream>

#include <Eigen/Dense>

Eigen::Quaterniond quatMulti(const Eigen::Quaterniond& q1, const Eigen::Quaterniond& q2)
{
    return (Eigen::Quaterniond(
            q1.w()*q2.w()-q1.x()*q2.x()-q1.y()*q2.y()-q1.z()*q2.z(),
            q1.w()*q2.x()+q1.x()*q2.w()+q1.y()*q2.z()-q1.z()*q2.y(),
            q1.w()*q2.y()-q1.x()*q2.z()+q1.y()*q2.w()+q1.z()*q2.x(),
            q1.w()*q2.z()+q1.x()*q2.y()-q1.y()*q2.x()+q1.z()*q2.w()));
}

int main() {

    Eigen::Matrix4d T_cl_cr = Eigen::Matrix4d::Identity();
    T_cl_cr(0,3) = -0.24;
    Eigen::Matrix4d T_i_cl;
    T_i_cl << 5.2513478829e-4 , -2.81142643e-2, 9.99604578e-1, 2.3856,
    -9.98958354885e-1, -4.562488357451e-2, -7.58422148e-4, -0.058,
    4.562816497e-2, -9.985629465e-1, -2.81089384e-2, 0.377,
    0,0,0,1;
    std::cout << T_i_cl * T_cl_cr << std::endl;

//    Eigen::Vector3d w(0.01, 0.02, 0.03);
//    Eigen::Vector3d w_tmp;
//
//    w_tmp = w.normalized();
//    double tmp = w.x() / w_tmp.x();
//
//    Eigen::AngleAxisd angle_axisd_01 = Eigen::AngleAxisd(tmp, w_tmp);
//    Eigen::Matrix3d rotation_tmp;
//    rotation_tmp = angle_axisd_01.toRotationMatrix();
//
//    Eigen::Quaterniond quat_ori(1., 2., 3., 4.);
//    quat_ori.normalize();
//
//    Eigen::Matrix3d rotation, rotation_result;
//    rotation = quat_ori.matrix();
//    rotation_result = rotation * rotation_tmp;
//
//    Eigen::Quaterniond quat_tmp(1, 0.5*w.x(), 0.5*w.y(), 0.5*w.z());
//    Eigen::Quaterniond quat_result;
//    //quat_result = quat_ori*quat_tmp;
//    quat_result = quatMulti(quat_ori, quat_tmp);
//    quat_result.normalize();
//
//    std::cout<<"quat:"<<std::endl<<quat_result.toRotationMatrix()<<std::endl;
//    std::cout<<"rota:"<<std::endl<<Eigen::Quaterniond(rotation_result).toRotationMatrix()<<std::endl;

    return 0;
}

