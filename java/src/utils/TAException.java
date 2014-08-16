package utils;

public class TAException extends RuntimeException
{
    private static final long serialVersionUID = 1L;

    public TAException(String message)
    {
        super(message);
    }

    public TAException()
    {
        super();
    }

}
