package utils;

public class TAException extends RuntimeException
{
    public TAException(String message)
    {
        super(message);
    }

    public TAException()
    {
        super();
    }

    private static final long serialVersionUID = 1L;
}
