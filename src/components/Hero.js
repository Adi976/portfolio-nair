import React from 'react';
import styled from 'styled-components';
import { motion } from 'framer-motion';
import { useInView } from 'react-intersection-observer';
import { FaArrowRight } from 'react-icons/fa';

const HeroSection = styled.section`
  min-height: 100vh;
  display: flex;
  align-items: center;
  padding: 120px 0 80px;
  background: linear-gradient(135deg, ${({ theme }) => theme.colors.lightBg} 0%, ${({ theme }) => theme.colors.white} 100%);
  position: relative;
  overflow: hidden;

  &::before {
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background: radial-gradient(circle at 50% 50%, rgba(0, 113, 227, 0.1) 0%, transparent 70%);
    pointer-events: none;
  }
`;

const HeroContent = styled(motion.div)`
  display: flex;
  align-items: center;
  gap: 60px;
  max-width: 1200px;
  margin: 0 auto;
  padding: 0 20px;

  @media (max-width: 768px) {
    flex-direction: column;
    text-align: center;
  }
`;

const TextContent = styled.div`
  flex: 1;
`;

const ProfileImage = styled(motion.div)`
  flex: 1;
  display: flex;
  justify-content: center;
  align-items: center;
  position: relative;

  img {
    width: 300px;
    height: 300px;
    border-radius: 50%;
    object-fit: cover;
    border: 5px solid ${({ theme }) => theme.colors.accent};
    box-shadow: 0 20px 40px rgba(0, 0, 0, 0.1);
    display: block;
    background-color: #f0f0f0;
  }

  @media (max-width: 768px) {
    margin-top: 40px;
    
    img {
      width: 250px;
      height: 250px;
    }
  }
`;

const Title = styled(motion.h1)`
  font-size: 4rem;
  font-weight: 700;
  line-height: 1.1;
  margin-bottom: 24px;
  background: linear-gradient(45deg, ${({ theme }) => theme.colors.primary}, ${({ theme }) => theme.colors.accent});
  -webkit-background-clip: text;
  -webkit-text-fill-color: transparent;

  @media (max-width: 1024px) {
    font-size: 3rem;
  }

  @media (max-width: 768px) {
    font-size: 2.5rem;
  }
`;

const Description = styled(motion.p)`
  font-size: 1.25rem;
  color: #666;
  margin-bottom: 40px;
  line-height: 1.6;
  font-family: ${({ theme }) => theme.fonts.body};
`;

const CTAButton = styled(motion.a)`
  display: inline-flex;
  align-items: center;
  gap: 10px;
  background-color: ${({ theme }) => theme.colors.accent};
  color: white;
  padding: 16px 32px;
  border-radius: 30px;
  font-weight: 500;
  transition: ${({ theme }) => theme.transition};

  &:hover {
    transform: translateY(-2px);
    box-shadow: 0 10px 20px rgba(0, 113, 227, 0.2);
  }
`;

const Hero = () => {
  const [ref, inView] = useInView({
    triggerOnce: true,
    threshold: 0.1
  });

  return (
    <HeroSection id="home">
      <HeroContent
        ref={ref}
        initial={{ opacity: 0, y: 20 }}
        animate={inView ? { opacity: 1, y: 0 } : {}}
        transition={{ duration: 0.6 }}
      >
        <TextContent>
          <Title
            initial={{ opacity: 0, y: 20 }}
            animate={inView ? { opacity: 1, y: 0 } : {}}
            transition={{ duration: 0.6, delay: 0.2 }}
          >
            Hi, I'm Adithya Nair
          </Title>
          <Description
            initial={{ opacity: 0, y: 20 }}
            animate={inView ? { opacity: 1, y: 0 } : {}}
            transition={{ duration: 0.6, delay: 0.4 }}
          >
            Driven by curiosity, fueled by perseverance.
          </Description>
          <CTAButton
            href="#contact"
            initial={{ opacity: 0, y: 20 }}
            animate={inView ? { opacity: 1, y: 0 } : {}}
            transition={{ duration: 0.6, delay: 0.6 }}
            whileHover={{ scale: 1.05 }}
            whileTap={{ scale: 0.95 }}
          >
            Get In Touch
            <FaArrowRight />
          </CTAButton>
        </TextContent>
        <ProfileImage
          initial={{ opacity: 0, scale: 0.8 }}
          animate={inView ? { opacity: 1, scale: 1 } : {}}
          transition={{ duration: 0.6, delay: 0.3 }}
        >
          <img 
            src={process.env.PUBLIC_URL + "/dp.jpg"} 
            alt="Adithya Nair" 
            onError={(e) => {
              console.error('Image failed to load:', e);
              console.log('Attempted to load from:', process.env.PUBLIC_URL + "/dp.jpg");
              e.target.style.border = '2px solid red';
            }}
            onLoad={() => console.log('Image loaded successfully')}
          />
        </ProfileImage>
      </HeroContent>
    </HeroSection>
  );
};

export default Hero; 